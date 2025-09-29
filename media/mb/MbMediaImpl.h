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

#ifndef content_media_MbMediaImpl_h
#define content_media_MbMediaImpl_h

#include "base/task/task_runner.h"
#include "base/threading/thread.h"
#include "cc/trees/layer_tree_settings.h"
#include "media/audio/audio_manager.h"
#include "media/audio/fake_audio_log_factory.h"
#include "media/base/media_player_logging_id.h"
#include "media/base/renderer_factory_selector.h"
#include "media/mb/renderer_webmediaplayer_delegate.h"
#include "media/renderers/default_decoder_factory.h"
#include "media/renderers/default_renderer_factory.h"
#include "third_party/blink/public/platform/media/resource_fetch_context.h"
#include "third_party/blink/public/platform/media/url_index.h"
#include "third_party/blink/public/platform/web_media_player.h"
#include "third_party/blink/public/platform/web_media_player_source.h"
#include "third_party/blink/public/web/modules/media/audio/audio_device_factory.h"
#include "third_party/blink/public/web/modules/media/audio/audio_output_ipc_factory.h"
#include <memory>

namespace blink {
class WebMediaPlayerClient;
class MediaInspectorContext;
class WebMediaPlayerEncryptedMediaClient;
}

namespace content {
class WebLocalFrameClientImpl;

class MbMediaImpl {
public:
    MbMediaImpl(WebLocalFrameClientImpl* client)
        : m_webFrameClient(client)
    {
    }
    ~MbMediaImpl();

    std::unique_ptr<blink::WebMediaPlayer> createMediaPlayer(
        const blink::WebMediaPlayerSource& source,
        blink::WebMediaPlayerClient* client,
        blink::MediaInspectorContext* inspector_context,
        blink::WebMediaPlayerEncryptedMediaClient* encrypted_client,
        blink::WebContentDecryptionModule* initial_cdm,
        const blink::WebString& sink_id,
        const cc::LayerTreeSettings& settings,
        scoped_refptr<base::TaskRunner> compositor_worker_task_runner);

    void ensureDecoderFactory();

private:
    std::unique_ptr<media::RendererFactorySelector> createRendererFactorySelector(
        media::MediaPlayerLoggingID player_id,
        media::MediaLog* media_log,
        blink::WebURL url,
        media::DecoderFactory* decoder_factory);

    std::unique_ptr<media::DefaultRendererFactory> createDefaultRendererFactory(
        media::MediaPlayerLoggingID player_id,
        media::MediaLog* media_log,
        media::DecoderFactory* decoder_factory);

    scoped_refptr<base::SingleThreadTaskRunner> getMediaThreadTaskRunner();

    scoped_refptr<base::SingleThreadTaskRunner> getOrCreateVideoFrameCompositorTaskRunner(WebLocalFrameClientImpl* impl);

    std::unique_ptr<media::DefaultDecoderFactory> m_decoderFactory;
    std::unique_ptr<base::Thread> m_mediaThread;
    std::unique_ptr<blink::ResourceFetchContext> m_fetchContext;
    std::unique_ptr<blink::UrlIndex> m_urlIndex;
    media::RendererWebMediaPlayerDelegate* m_delegate = nullptr;
    std::unique_ptr<media::AudioManager> m_audioManager;
    std::unique_ptr<media::FakeAudioLogFactory> m_fakeAudioLogImpl;
    WebLocalFrameClientImpl* m_webFrameClient = nullptr;
};

}

#endif