// Copyright 2013 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/public/platform/modules/mediastream/web_media_stream_audio_sink.h"

#include "base/check.h"
#include "third_party/blink/public/platform/modules/mediastream/web_media_stream_source.h"
#include "third_party/blink/public/platform/modules/mediastream/web_media_stream_track.h"
#include "third_party/blink/renderer/platform/mediastream/media_stream_audio_track.h"
#include "third_party/blink/renderer/platform/mediastream/media_stream_component.h"

namespace blink {

void WebMediaStreamSource::Reset(void)
{
    *(int*)1 = 1;
}

void WebMediaStreamAudioSink::AddToAudioTrack(WebMediaStreamAudioSink* sink, const blink::WebMediaStreamTrack& track)
{
    //     DCHECK(track.Source().GetType() == blink::WebMediaStreamSource::kTypeAudio);
    //     static_cast<MediaStreamComponent*>(track)->AddSink(sink);
    *(int*)1 = 1;
}

void WebMediaStreamAudioSink::RemoveFromAudioTrack(WebMediaStreamAudioSink* sink, const blink::WebMediaStreamTrack& track)
{
    //     MediaStreamAudioTrack* native_track = MediaStreamAudioTrack::From(track);
    //     DCHECK(native_track);
    //     native_track->RemoveSink(sink);
    *(int*)1 = 1;
}

media::AudioParameters WebMediaStreamAudioSink::GetFormatFromAudioTrack(const blink::WebMediaStreamTrack& track)
{
    //     MediaStreamAudioTrack* native_track = MediaStreamAudioTrack::From(track);
    //     DCHECK(native_track);
    //     return native_track->GetOutputFormat();
    *(int*)1 = 1;
    media::AudioParameters* ret = new media::AudioParameters();
    return *ret;
}

} // namespace blink
