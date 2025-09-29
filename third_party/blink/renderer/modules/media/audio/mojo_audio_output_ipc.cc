// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#if defined(ENABLE_MB_MEDIA) 
#include "third_party/blink/renderer/modules/media/audio/mojo_audio_output_ipc.h"

#include <utility>

#include "base/metrics/histogram_macros.h"
#include "base/threading/thread.h"
#if defined(OS_WIN) 
#include "base/win/scoped_com_initializer.h"
#include "media/audio/win/audio_low_latency_output_win.h"
#endif // OS_WIN
#include "media/audio/audio_device_description.h"
#include "media/audio/fake_audio_log_factory.h"
#include "media/audio/audio_manager.h"
#include "media/mojo/mojom/audio_output_stream.mojom-blink.h"
#include "media/mojo/mojom/audio_data_pipe.mojom.h"
#include "media/mojo/mojom/audio_data_pipe.mojom-blink.h"
#include "media/mojo/mojom/audio_data_pipe.mojom-forward.h"
#include "media/mojo/mojom/audio_data_pipe.mojom-blink-forward.h"
#include "mojo/public/cpp/bindings/callback_helpers.h"
#include "mojo/public/cpp/system/platform_handle.h"
#include "third_party/blink/renderer/platform/wtf/functional.h"
#include "services/audio/sync_reader.h"
#include "services/audio/output_stream.h"

namespace {
    scoped_refptr<base::SingleThreadTaskRunner> getMediaThreadTaskRunner() {
        static base::Thread* mediaUtilThread = nullptr;
        if (!mediaUtilThread) {
            mediaUtilThread = new base::Thread("MediaUitl");
            base::Thread::Options options;
            mediaUtilThread->StartWithOptions(std::move(options));

#ifdef _WIN32
            mediaUtilThread->task_runner()->PostTask(FROM_HERE, base::BindOnce([]() {
                new base::win::ScopedCOMInitializer();
            }));
#endif // _WIN32
        }

        return mediaUtilThread->task_runner();
    }
} // namespace

namespace blink {
    namespace mb_media {
        class MainThread final : public media::AudioThread {
        public:
            MainThread();

            MainThread(const MainThread&) = delete;
            MainThread& operator=(const MainThread&) = delete;

            ~MainThread() final;

            // AudioThread implementation.
            void Stop() final;
            bool IsHung() const final;
            base::SingleThreadTaskRunner* GetTaskRunner() final;
            base::SingleThreadTaskRunner* GetWorkerTaskRunner() final;

        private:
            scoped_refptr<base::SingleThreadTaskRunner> task_runner_;

            // This is not started until the first time GetWorkerTaskRunner() is called.
            scoped_refptr<base::SingleThreadTaskRunner> worker_task_runner_ = nullptr;
        };

        MainThread::MainThread()
            : task_runner_(base::ThreadTaskRunnerHandle::Get()),
            worker_task_runner_(base::ThreadTaskRunnerHandle::Get()) 
        {
        }

        MainThread::~MainThread() 
        {
            DCHECK(task_runner_->BelongsToCurrentThread());
        }

        void MainThread::Stop() 
        {
            DCHECK(task_runner_->BelongsToCurrentThread());

            if (worker_task_runner_) {
                worker_task_runner_ = nullptr;
            }
        }

        bool MainThread::IsHung() const 
        {
            return false;
        }

        base::SingleThreadTaskRunner* MainThread::GetTaskRunner() 
        {
            return task_runner_.get();
        }

        base::SingleThreadTaskRunner* MainThread::GetWorkerTaskRunner() 
        {
            DCHECK(
                task_runner_->BelongsToCurrentThread() ||
                (worker_task_runner_ && worker_task_runner_->BelongsToCurrentThread()));
            return worker_task_runner_.get();
        }

        class MbAudioOutputImpl {
        public:
            MbAudioOutputImpl(MojoAudioOutputIPC* ipc, base::SingleThreadTaskRunner* runner)
                : m_foreignSocket(), m_ipc(ipc), m_runner(runner)
            {
                m_fakeAudioLogFactory = std::make_unique<media::FakeAudioLogFactory>();
                // todo(mb): AudioManager 其实是可以做成单例共用的, 但是目前切换视频网站会报错, 后续研究
                m_audioManager = media::AudioManager::Create(std::make_unique<mb_media::MainThread>(), m_fakeAudioLogFactory.get());
                m_audioParameters = m_audioManager->GetDefaultOutputStreamParameters();
            };

            ~MbAudioOutputImpl() 
            {
                m_isDestory = true;
                m_outputStream = nullptr;
                m_audioManager->Shutdown();
                m_audioManager = nullptr;
                m_fakeAudioLogFactory = nullptr;
                m_ipc = nullptr;
                m_runner = nullptr;
            }

            void streamCreated(
                mojo::PendingRemote<media::mojom::AudioOutputStream> ,
                media::mojom::ReadWriteAudioDataPipePtr dataPipe) {
                if (!dataPipe) {
                    return;
                }

                if (!m_ipc || m_ipc->m_isMbAudioOutputDestory)
                    return;

                m_runner->PostTask(FROM_HERE, base::BindOnce([](MbAudioOutputImpl* self, media::mojom::ReadWriteAudioDataPipePtr&& dataPipe) {
                    mojo::PendingRemote<media::mojom::blink::AudioOutputStream> stream;
                    self->m_streamReceiver = stream.InitWithNewPipeAndPassReceiver();
                    self->m_ipc->Created(std::move(stream), { absl::in_place, std::move(dataPipe->shared_memory), std::move(dataPipe->socket) });
                }, base::Unretained(this), std::move(dataPipe)));
            }

            base::WeakPtr<MbAudioOutputImpl> getWeakPtr()
            {
                return m_weakPtrFactory.GetWeakPtr();
            }

            void createStream(media::AudioParameters params)
            {
                if (!m_ipc || m_ipc->m_isMbAudioOutputDestory)
                    return;

                getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](MbAudioOutputImpl* self, media::AudioParameters params) {
                    if (!self || self->m_isDestory)
                        return;

                    mojo::PendingRemote<media::mojom::AudioOutputStream> stream;
                    mojo::PendingAssociatedRemote<media::mojom::AudioOutputStreamObserver> observer;
                    mojo::PendingRemote<media::mojom::AudioLog> log;

                    self->m_outputStream = std::make_unique<audio::OutputStream>(
                        base::BindOnce(&mb_media::MbAudioOutputImpl::streamCreated,
                            self->getWeakPtr(), std::move(stream)),
                        base::DoNothing(),
                        audio::OutputController::ManagedDeviceOutputStreamCreateCallback(),
                        stream.InitWithNewPipeAndPassReceiver(), std::move(observer), std::move(log),
                        self->m_audioManager->Get(), "", params, &self->m_coordinator, self->m_groupId);
                }, base::Unretained(this), params));
            }

            // todo(mb): 设备认证的流程比较复杂, 这里先跳过认证流程, 直接使用默认设备, 后续可以研究
            void authDevice() 
            {
                if (!m_ipc || m_ipc->m_isMbAudioOutputDestory)
                    return;

                m_runner->PostTask(FROM_HERE, base::BindOnce([](const MojoAudioOutputIPC* ipc) {
                    if (!ipc || ipc->m_isMbAudioOutputDestory)
                        return;

                    ipc->delegate_->OnDeviceAuthorized(media::OUTPUT_DEVICE_STATUS_OK, ipc->m_mbImpl->m_audioParameters, "");
                }, base::Unretained(m_ipc)));
            }

            void play()
            {
                getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](base::WeakPtr<MbAudioOutputImpl> self) {
                    if (!self)
                        return;

                    self->m_outputStream->Play();
                }, getWeakPtr()));
            }

            void pause()
            {
                getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](base::WeakPtr<MbAudioOutputImpl> self) {
                    if (!self)
                        return;

                    self->m_outputStream->Pause();
                }, getWeakPtr()));
            }

            void flush()
            {
                getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](base::WeakPtr<MbAudioOutputImpl> self) {
                    if (!self)
                        return;

                    self->m_outputStream->Flush();
                }, getWeakPtr()));
            }
            void setVolume(double volume)
            {
                getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](base::WeakPtr<MbAudioOutputImpl> self, double vol) {
                    if (!self)
                        return;

                    self->m_outputStream->SetVolume(vol);
                }, getWeakPtr(), volume));
            }

         private:
            bool m_isDestory = false;
            // std::unique_ptr<media::FakeAudioLogFactory> m_fakeAudioLogFactory;
            std::unique_ptr<media::FakeAudioLogFactory> m_fakeAudioLogFactory;
            std::unique_ptr<media::AudioManager> m_audioManager;
            media::AudioParameters m_audioParameters;
            // static media::AudioManager* m_audioManager;
            std::unique_ptr<audio::OutputStream> m_outputStream;

            base::CancelableSyncSocket m_foreignSocket;
            // audio::SyncReader* reader_ = nullptr;
            mojo::PendingReceiver<media::mojom::blink::AudioOutputStream> m_streamReceiver;
            //media::AudioOutputStream* m_stream;
            // media::AudioParameters m_audioParameters;
            audio::LoopbackCoordinator m_coordinator;
            base::UnguessableToken m_groupId;
            base::WeakPtrFactory<MbAudioOutputImpl> m_weakPtrFactory { this };
            MojoAudioOutputIPC* m_ipc;
            base::SingleThreadTaskRunner* m_runner;
        };
    }

    namespace {

        void TrivialAuthorizedCallback(media::mojom::blink::OutputDeviceStatus, const media::AudioParameters&, const String&) {}

    } // namespace

    MojoAudioOutputIPC::MojoAudioOutputIPC(FactoryAccessorCB factory_accessor, scoped_refptr<base::SingleThreadTaskRunner> io_task_runner)
        : factory_accessor_(std::move(factory_accessor))
        , io_task_runner_(std::move(io_task_runner)) {
        getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](MojoAudioOutputIPC* self) {
            if (self->m_isMbAudioOutputDestory)
                return;

            self->m_mbImpl = std::make_unique<mb_media::MbAudioOutputImpl>(self, self->io_task_runner_.get());
        }, base::Unretained(this)));
    }

    MojoAudioOutputIPC::~MojoAudioOutputIPC() {
        DCHECK(!AuthorizationRequested() && !StreamCreationRequested()) << "CloseStream must be called before destructing the AudioOutputIPC";
        // No sequence check.
        // Destructing |weak_factory_| on any sequence is safe since it's not used
        // after the final call to CloseStream, where its pointers are invalidated.
        if (m_mbImpl) {
            getMediaThreadTaskRunner()->DeleteSoon(FROM_HERE, std::move(m_mbImpl));
            m_mbImpl = nullptr;
            m_isMbAudioOutputDestory = true;
        }
    }

    void MojoAudioOutputIPC::RequestDeviceAuthorization(
        media::AudioOutputIPCDelegate* delegate, const base::UnguessableToken& session_id, const std::string& device_id) {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        DCHECK(delegate);
        DCHECK(!delegate_);
        DCHECK(!AuthorizationRequested());
        DCHECK(!StreamCreationRequested());
        delegate_ = delegate;

        // We wrap the callback in a WrapCallbackWithDefaultInvokeIfNotRun to detect
        // the case when the mojo connection is terminated prior to receiving the
        // response. In this case, the callback runner will be destructed and call
        // ReceivedDeviceAuthorization with an error.
        DoRequestDeviceAuthorization(session_id, device_id,
            mojo::WrapCallbackWithDefaultInvokeIfNotRun(
                WTF::BindOnce(&MojoAudioOutputIPC::ReceivedDeviceAuthorization, weak_factory_.GetWeakPtr(), base::TimeTicks::Now()),
                static_cast<media::mojom::blink::OutputDeviceStatus>(media::OutputDeviceStatus::OUTPUT_DEVICE_STATUS_ERROR_INTERNAL),
                media::AudioParameters::UnavailableDeviceParams(), String()));
    }

    void MojoAudioOutputIPC::CreateStream(media::AudioOutputIPCDelegate* delegate, const media::AudioParameters& params) {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        DCHECK(delegate);
        DCHECK(!StreamCreationRequested());
        if (!AuthorizationRequested()) {
            DCHECK(!delegate_);
            delegate_ = delegate;
            // No authorization requested yet. Request one for the default device.
            // Since the delegate didn't explicitly request authorization, we shouldn't
            // send a callback to it.
            DoRequestDeviceAuthorization(
                /*session_id=*/base::UnguessableToken(), media::AudioDeviceDescription::kDefaultDeviceId, WTF::BindOnce(&TrivialAuthorizedCallback));
        }

        DCHECK_EQ(delegate_, delegate);

        m_mbImpl->createStream(params);
    }

    void MojoAudioOutputIPC::PlayStream() {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        expected_state_ = kPlaying;
        //if (stream_.is_bound())
        //    stream_->Play();
        if (stream_.is_bound()) {
            m_mbImpl->play();
        }
    }

    void MojoAudioOutputIPC::PauseStream() {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        expected_state_ = kPaused;
        if (stream_.is_bound()) {
            m_mbImpl->pause();
        }
    }

    void MojoAudioOutputIPC::FlushStream() {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        if (stream_.is_bound()) {
            m_mbImpl->flush();
        }
    }

    void MojoAudioOutputIPC::CloseStream() {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        stream_provider_.reset();
        stream_.reset();
        receiver_.reset();
        delegate_ = nullptr;
        expected_state_ = kPaused;
        volume_ = absl::nullopt;

        // Cancel any pending callbacks for this stream.
        weak_factory_.InvalidateWeakPtrs();
    }

    void MojoAudioOutputIPC::SetVolume(double volume) {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        volume_ = volume;
        if (stream_.is_bound()) {
            m_mbImpl->setVolume(volume);
        }
        // else volume is set when the stream is created.
    }

    void MojoAudioOutputIPC::ProviderClientBindingDisconnected(uint32_t disconnect_reason, const std::string& description) {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        DCHECK(delegate_);
        if (disconnect_reason == static_cast<uint32_t>(media::mojom::blink::AudioOutputStreamObserver::DisconnectReason::kPlatformError)) {
            delegate_->OnError();
        }
        // Otherwise, disconnection was due to the frame owning |this| being
        // destructed or having a navigation. In this case, |this| will soon be
        // cleaned up.
    }

    bool MojoAudioOutputIPC::AuthorizationRequested() const {
        return stream_provider_.is_bound();
    }

    bool MojoAudioOutputIPC::StreamCreationRequested() const {
        return receiver_.is_bound();
    }

    mojo::PendingReceiver<media::mojom::blink::AudioOutputStreamProvider> MojoAudioOutputIPC::MakeProviderReceiver() {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        DCHECK(!AuthorizationRequested());

        // Don't set a connection error handler.
        // There are three possible reasons for a connection error.
        // 1. The connection is broken before authorization was completed. In this
        //    case, the WrapCallbackWithDefaultInvokeIfNotRun wrapping the callback
        //    will call the callback with failure.
        // 2. The connection is broken due to authorization being denied. In this
        //    case, the callback was called with failure first, so the state of the
        //    stream provider is irrelevant.
        // 3. The connection was broken after authorization succeeded. This is because
        //    of the frame owning this stream being destructed, and this object will
        //    be cleaned up soon.
        return stream_provider_.BindNewPipeAndPassReceiver();
    }

    void MojoAudioOutputIPC::DoRequestDeviceAuthorization(const base::UnguessableToken& session_id, const std::string& device_id, AuthorizationCB callback) {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        auto* factory = factory_accessor_.Run();
        if (!factory) {
            LOG(ERROR) << "MojoAudioOutputIPC failed to acquire factory";

            // Create a provider receiver for consistency with the normal case.
            MakeProviderReceiver();
            // Resetting the callback asynchronously ensures consistent behaviour with
            // when the factory is destroyed before reply, i.e. calling
            // OnDeviceAuthorized with ERROR_INTERNAL in the normal case.
            // The AudioOutputIPCDelegate will call CloseStream as necessary.
            io_task_runner_->PostTask(FROM_HERE, WTF::BindOnce([](AuthorizationCB cb) {}, std::move(callback)));
            return;
        }

        static_assert(sizeof(int) == sizeof(int32_t), "sizeof(int) == sizeof(int32_t)");
        factory->RequestDeviceAuthorization(MakeProviderReceiver(), session_id.is_empty() ? absl::optional<base::UnguessableToken>() : session_id,
            String::FromUTF8(device_id), std::move(callback));
    }

    void MojoAudioOutputIPC::ReceivedDeviceAuthorization(
        base::TimeTicks auth_start_time, media::mojom::blink::OutputDeviceStatus status, const media::AudioParameters& params, const String& device_id) const {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        DCHECK(delegate_);

        // Times over 15 s should be very rare, so we don't lose interesting data by
        // making it the upper limit.
        UMA_HISTOGRAM_CUSTOM_TIMES(
            "Media.Audio.Render.OutputDeviceAuthorizationTime", base::TimeTicks::Now() - auth_start_time, base::Milliseconds(1), base::Seconds(15), 100);
        
        if (m_isMbAudioOutputDestory)
            return;

        getMediaThreadTaskRunner()->PostTask(FROM_HERE, base::BindOnce([](const MojoAudioOutputIPC* self) {
            if (!self || self->m_isMbAudioOutputDestory)
                return;

            self->m_mbImpl->authDevice();
        }, base::Unretained(this)));
    }

    void MojoAudioOutputIPC::Created(
        mojo::PendingRemote<media::mojom::blink::AudioOutputStream> pending_stream, media::mojom::blink::ReadWriteAudioDataPipePtr data_pipe) {
        DCHECK(io_task_runner_->RunsTasksInCurrentSequence());
        DCHECK(delegate_);

        stream_.reset();
        stream_.Bind(std::move(pending_stream));

        DCHECK(data_pipe->socket.is_valid_platform_file());
        base::ScopedPlatformFile socket_handle = data_pipe->socket.TakePlatformFile();

        base::UnsafeSharedMemoryRegion& shared_memory_region = data_pipe->shared_memory;
        DCHECK(shared_memory_region.IsValid());

        delegate_->OnStreamCreated(std::move(shared_memory_region), std::move(socket_handle), expected_state_ == kPlaying);

        if (volume_) {
            m_mbImpl->setVolume(volume_.value());
        }


        if (expected_state_ == kPlaying) {
            m_mbImpl->play();
        }

    }

} // namespace blink
#endif // ENABLE_MB_MEDIA