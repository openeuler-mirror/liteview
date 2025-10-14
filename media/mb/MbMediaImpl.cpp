//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//

#include "media/mb/MbMediaImpl.h"

#include "base/threading/thread.h"
#include "cc/trees/layer_tree_settings.h"
#include "components/viz/common/gpu/raster_context_provider.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "media/audio/audio_manager.h"
#include "media/audio/fake_audio_log_factory.h"
#include "media/base/demuxer.h"
#include "media/base/media_log.h"
#include "media/base/media_player_logging_id.h"
#include "media/base/renderer_factory_selector.h"
#include "media/mb/batching_media_log.h"
#include "media/mb/renderer_webmediaplayer_delegate.h"
#include "media/renderers/default_renderer_factory.h"
#include "third_party/blink/public/common/thread_safe_browser_interface_broker_proxy.h"
#include "third_party/blink/public/platform/media/resource_fetch_context.h"
#include "third_party/blink/public/platform/media/url_index.h"
#include "third_party/blink/public/platform/media/video_frame_compositor.h"
#include "third_party/blink/public/platform/media/web_media_player_builder.h"
#include "third_party/blink/public/platform/web_media_player.h"
#include "third_party/blink/public/platform/web_media_player_source.h"
#include "third_party/blink/public/platform/web_surface_layer_bridge.h"
#include "third_party/blink/public/web/modules/media/audio/audio_device_factory.h"
#include "third_party/blink/public/web/modules/media/audio/audio_output_ipc_factory.h"
#include "third_party/blink/public/web/web_local_frame.h"

#include "base/task/task_runner.h"
#include <memory>

#if defined(OS_LINUX)
#include <dlfcn.h>
#endif

namespace content {

class FrameFetchContext : public blink::ResourceFetchContext {
public:
    explicit FrameFetchContext(blink::WebLocalFrame* frame)
        : frame_(frame)
    {
        DCHECK(frame_);
    }

    FrameFetchContext(const FrameFetchContext&) = delete;
    FrameFetchContext& operator=(const FrameFetchContext&) = delete;

    ~FrameFetchContext() override = default;

    blink::WebLocalFrame* frame() const { return frame_; }

    // blink::ResourceFetchContext implementation.
    std::unique_ptr<blink::WebAssociatedURLLoader> CreateUrlLoader(
        const blink::WebAssociatedURLLoaderOptions& options) override
    {
        return frame_->CreateAssociatedURLLoader(options);
    }

private:
    blink::WebLocalFrame* frame_;
};

media::GpuVideoAcceleratorFactories* emptyGetGpuCB()
{
    //*(int*)1 = 1;();
    return nullptr;
}

bool emptyCB(base::OnceClosure closure)
{
    //*(int*)1 = 1;();
    return true;
}

int64_t emptyAdjustAmountOfExternalAllocatedMemory(int64_t change_in_bytes)
{
    //*(int*)1 = 1;();
    return 0;
}

void RequestRoutingTokenCallback(media::RoutingTokenCallback cb)
{
    *(int*)1 = 1;
}

std::unique_ptr<blink::WebSurfaceLayerBridge> emptyBridgeCreate(
    blink::WebSurfaceLayerBridgeObserver* observer, cc::UpdateSubmissionStateCB update_submission_state_callback)
{
    // todo(mb): 目前没有使用 surface 的方式上屏
    // return std::make_unique<SurfaceLayerBridge>(parent_frame_sink_id, contains_video, observer, std::move(update_submission_state_callback));
    *(int*)1 = 1;
    return nullptr;
}

MbMediaImpl::~MbMediaImpl()
{
    m_webFrameClient = nullptr;
    if (m_delegate) {
        delete m_delegate;
        m_delegate = nullptr;
    }
    if (m_mediaThread) {
        m_mediaThread->Stop();
    }
}

std::unique_ptr<blink::WebMediaPlayer> MbMediaImpl::createMediaPlayer(
    const blink::WebMediaPlayerSource& source,
    blink::WebMediaPlayerClient* client,
    blink::MediaInspectorContext* inspectorContext,
    blink::WebMediaPlayerEncryptedMediaClient* encryptedClient,
    blink::WebContentDecryptionModule* initialCdm,
    const blink::WebString& sinkId,
    const cc::LayerTreeSettings& settings,
    scoped_refptr<base::TaskRunner> compositorWorkerTaskRunner)
{

    if (source.IsMediaStream()) { // todo(mb): 目前不支持流形式
        *(int*)1 = 1;
    }

    scoped_refptr<media::SwitchableAudioRendererSink> audioRendererSink = blink::AudioDeviceFactory::GetInstance()->NewSwitchableAudioRendererSink(
        blink::WebAudioDeviceSourceType::kMediaElement,
        m_webFrameClient->getFrame()->GetLocalFrameToken(),
        media::AudioSinkParameters(/*session_id=*/base::UnguessableToken(),
            sinkId.Utf8()));

    ensureDecoderFactory();

    blink::WebURL url = source.GetAsURL();

    media::MediaPlayerLoggingID playerId = media::GetNextMediaPlayerLoggingID();

    std::vector<std::unique_ptr<BatchingMediaLog::EventHandler>> handlers;

    auto mediaLog = std::make_unique<content::BatchingMediaLog>(
        blink::WebLocalFrame::FromFrameToken(m_webFrameClient->getFrame()->GetLocalFrameToken())->GetTaskRunner(blink::TaskType::kInternalMedia),
        std::move(handlers));

    auto factorySelector = createRendererFactorySelector(
        playerId, mediaLog.get(), url,
        m_decoderFactory.get());

    scoped_refptr<base::SingleThreadTaskRunner> mediaTaskRunner = getMediaThreadTaskRunner();

    auto videoFrameCompositorTaskRunner = getOrCreateVideoFrameCompositorTaskRunner(m_webFrameClient);
    auto vfc = std::make_unique<blink::VideoFrameCompositor>(
        videoFrameCompositorTaskRunner, nullptr);

    mojo::PendingRemote<media::mojom::MediaMetricsProvider> metricsProvider;

    if (!m_fetchContext) {
        m_fetchContext = std::make_unique<FrameFetchContext>(m_webFrameClient->getFrame());
        m_urlIndex = std::make_unique<blink::UrlIndex>(
            m_fetchContext.get(),
            blink::WebLocalFrame::FromFrameToken(m_webFrameClient->getFrame()->GetLocalFrameToken())->GetTaskRunner(blink::TaskType::kInternalMedia));
    }

    m_delegate = new media::RendererWebMediaPlayerDelegate(m_webFrameClient);

    return base::WrapUnique(blink::WebMediaPlayerBuilder::Build(
        m_webFrameClient->getFrame(), client, encryptedClient, m_delegate,
        std::move(factorySelector), m_urlIndex.get(), std::move(vfc),
        std::move(mediaLog), playerId,
        base::BindRepeating(&emptyCB),
        std::move(audioRendererSink), std::move(mediaTaskRunner),
        std::move(compositorWorkerTaskRunner),
        nullptr,
        std::move(videoFrameCompositorTaskRunner),
        base::BindRepeating(&emptyAdjustAmountOfExternalAllocatedMemory),
        initialCdm, base::BindRepeating(&RequestRoutingTokenCallback), nullptr,
        false, false,
        std::move(metricsProvider),
        base::BindOnce(&emptyBridgeCreate),
        nullptr,
        false,
        false,
        false,
        false,
        nullptr,
        nullptr));
}

void MbMediaImpl::ensureDecoderFactory()
{
    if (!m_decoderFactory) {
        std::unique_ptr<media::DecoderFactory> externalDecoderFactory { nullptr };

        m_decoderFactory = std::make_unique<media::DefaultDecoderFactory>(
            std::move(externalDecoderFactory));
    }
}

std::unique_ptr<media::RendererFactorySelector>
MbMediaImpl::createRendererFactorySelector(
    media::MediaPlayerLoggingID playerId,
    media::MediaLog* mediaLog,
    blink::WebURL url,
    media::DecoderFactory* decoderFactory)
{
    auto factorySelector = std::make_unique<media::RendererFactorySelector>();

    auto default_factory = createDefaultRendererFactory(
        playerId, mediaLog, decoderFactory);
    factorySelector->AddBaseFactory(media::RendererType::kDefault,
        std::move(default_factory));

    return factorySelector;
}

scoped_refptr<base::SingleThreadTaskRunner>
MbMediaImpl::getMediaThreadTaskRunner()
{
    if (!m_mediaThread) {
        m_mediaThread = std::make_unique<base::Thread>("Media");
        base::Thread::Options options;
        m_mediaThread->StartWithOptions(std::move(options));
    }
    return m_mediaThread->task_runner();
}

scoped_refptr<base::SingleThreadTaskRunner>
MbMediaImpl::getOrCreateVideoFrameCompositorTaskRunner(WebLocalFrameClientImpl* impl)
{
    auto renderThreadImpl = RenderThreadImpl::get();
    if (renderThreadImpl) {
        return renderThreadImpl->getCompositorTaskRunner();
    }

    return blink::WebLocalFrame::FromFrameToken(impl->getFrame()->GetLocalFrameToken())->GetTaskRunner(blink::TaskType::kInternalMediaRealTime);
}

std::unique_ptr<media::DefaultRendererFactory> MbMediaImpl::createDefaultRendererFactory(
    media::MediaPlayerLoggingID playerId,
    media::MediaLog* mediaLog,
    media::DecoderFactory* decoderFactory)
{
    auto defaultFactory = std::make_unique<media::DefaultRendererFactory>(
        mediaLog, decoderFactory,
        base::BindRepeating(&content::emptyGetGpuCB),
        playerId, nullptr);

    return defaultFactory;
}
}