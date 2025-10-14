// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/loader/resource/text_resource.h"

#include "third_party/blink/renderer/core/html/parser/text_resource_decoder.h"
#include "third_party/blink/renderer/platform/loader/fetch/resource_fetcher.h"
#include "third_party/blink/renderer/platform/loader/fetch/text_resource_decoder_options.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/shared_buffer.h"
#include "third_party/blink/renderer/platform/wtf/text/string_builder.h"

namespace blink {

namespace {

class SVGDocumentResourceFactory : public ResourceFactory {
public:
    SVGDocumentResourceFactory()
        : ResourceFactory(ResourceType::kSVGDocument, TextResourceDecoderOptions::kXMLContent)
    {
    }

    Resource* Create(const ResourceRequest& request, const ResourceLoaderOptions& options, const TextResourceDecoderOptions& decoder_options) const override
    {
        return MakeGarbageCollected<TextResource>(request, ResourceType::kSVGDocument, options, decoder_options);
    }
};

} // namespace

TextResource* TextResource::FetchSVGDocument(FetchParameters& params, ResourceFetcher* fetcher, ResourceClient* client)
{
    return To<TextResource>(fetcher->RequestResource(params, SVGDocumentResourceFactory(), client));
}

TextResource::TextResource(
    const ResourceRequest& resource_request, ResourceType type, const ResourceLoaderOptions& options, const TextResourceDecoderOptions& decoder_options)
    : Resource(resource_request, type, options)
    , decoder_(std::make_unique<TextResourceDecoder>(decoder_options))
{
}

TextResource::~TextResource() = default;

void TextResource::SetEncoding(const String& chs)
{
    decoder_->SetEncoding(WTF::TextEncoding(chs), TextResourceDecoder::kEncodingFromHTTPHeader);
}

WTF::TextEncoding TextResource::Encoding() const
{
    return decoder_->Encoding();
}

bool CheckNeedChangeEncodingToUtf8(const KURL& url)
{
    bool b = true;
    do {
        const String& url_str = url.GetString();
//         if (url_str.FindIgnoringCase("order.jd.com/center/list.action", 0) != WTF::kNotFound)
//             DebugBreak();

        String host = url.Host();
        if (host.FindIgnoringCase("h5static.m.jd.com", 0) != WTF::kNotFound ||
            host.FindIgnoringCase("order.jd.com", 0) != WTF::kNotFound ||
            host.FindIgnoringCase("static.360buyimg.com", 0) != WTF::kNotFound ||
            host.FindIgnoringCase("api.m.jd.com", 0) != WTF::kNotFound ||
            host.FindIgnoringCase("storage.jd.com", 0) != WTF::kNotFound)
            break;

        //https://static.360buyimg.com/im/js/im_icon_v5.js?sign=20131111        
        //if (url_str.length() < 100 && url_str.FindIgnoringCase("static.360buyimg.com/im/js", 0) != WTF::kNotFound)
        //    break;

        if (url_str.length() < 100 && url_str.FindIgnoringCase("weibo.com/js/visitor/mini_original.js", 0) != WTF::kNotFound)
            break;

        b = false;
    } while (false);

    return b;
}

String TextResource::DecodedText() const
{
    DCHECK(Data());

    if (CheckNeedChangeEncodingToUtf8(Url()))
        ((TextResource*)(this))->SetEncodingForTest("UTF-8");

    StringBuilder builder;
    for (const auto& span : *Data()) {
        builder.Append(decoder_->Decode(span.data(), span.size()));
    }
    builder.Append(decoder_->Flush());
    return builder.ToString();
}

String TextResource::RawText() const
{
    CHECK(RuntimeEnabledFeatures::ExperimentalWebSnapshotsEnabled());

    DCHECK(Data());

    StringBuilder builder;
    for (const auto& span : *Data())
        builder.Append(String(span.data(), span.size()));
    return builder.ToString();
}

} // namespace blink
