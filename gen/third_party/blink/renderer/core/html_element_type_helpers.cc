// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#include "third_party/blink/renderer/core/html_element_type_helpers.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"

namespace blink {
using HTMLTypeMap = HashMap<AtomicString, HTMLElementType>;

HTMLTypeMap CreateHTMLTypeMap()
{
    HTMLTypeMap html_type_map;
    html_type_map.ReserveCapacityForSize(141);
    static constexpr struct {
        const char* name;
        HTMLElementType type;
    } kTags[] = {
        { "a", HTMLElementType::kHTMLAnchorElement },
        { "abbr", HTMLElementType::kHTMLElement },
        { "acronym", HTMLElementType::kHTMLElement },
        { "address", HTMLElementType::kHTMLElement },
        { "applet", HTMLElementType::kHTMLUnknownElement },
        { "area", HTMLElementType::kHTMLAreaElement },
        { "article", HTMLElementType::kHTMLElement },
        { "aside", HTMLElementType::kHTMLElement },
        { "audio", HTMLElementType::kHTMLAudioElement },
        { "b", HTMLElementType::kHTMLElement },
        { "base", HTMLElementType::kHTMLBaseElement },
        { "basefont", HTMLElementType::kHTMLElement },
        { "bdi", HTMLElementType::kHTMLElement },
        { "bdo", HTMLElementType::kHTMLElement },
        { "bgsound", HTMLElementType::kHTMLUnknownElement },
        { "big", HTMLElementType::kHTMLElement },
        { "blockquote", HTMLElementType::kHTMLQuoteElement },
        { "body", HTMLElementType::kHTMLBodyElement },
        { "br", HTMLElementType::kHTMLBRElement },
        { "button", HTMLElementType::kHTMLButtonElement },
        { "canvas", HTMLElementType::kHTMLCanvasElement },
        { "caption", HTMLElementType::kHTMLTableCaptionElement },
        { "center", HTMLElementType::kHTMLElement },
        { "cite", HTMLElementType::kHTMLElement },
        { "code", HTMLElementType::kHTMLElement },
        { "col", HTMLElementType::kHTMLTableColElement },
        { "colgroup", HTMLElementType::kHTMLTableColElement },
        { "command", HTMLElementType::kHTMLUnknownElement },
        { "data", HTMLElementType::kHTMLDataElement },
        { "datalist", HTMLElementType::kHTMLDataListElement },
        { "dd", HTMLElementType::kHTMLElement },
        { "del", HTMLElementType::kHTMLModElement },
        { "details", HTMLElementType::kHTMLDetailsElement },
        { "dfn", HTMLElementType::kHTMLElement },
        { "dialog", HTMLElementType::kHTMLDialogElement },
        { "dir", HTMLElementType::kHTMLDirectoryElement },
        { "div", HTMLElementType::kHTMLDivElement },
        { "dl", HTMLElementType::kHTMLDListElement },
        { "dt", HTMLElementType::kHTMLElement },
        { "em", HTMLElementType::kHTMLElement },
        { "embed", HTMLElementType::kHTMLEmbedElement },
        { "fencedframe", HTMLElementType::kHTMLFencedFrameElement },
        { "fieldset", HTMLElementType::kHTMLFieldSetElement },
        { "figcaption", HTMLElementType::kHTMLElement },
        { "figure", HTMLElementType::kHTMLElement },
        { "font", HTMLElementType::kHTMLFontElement },
        { "footer", HTMLElementType::kHTMLElement },
        { "form", HTMLElementType::kHTMLFormElement },
        { "frame", HTMLElementType::kHTMLFrameElement },
        { "frameset", HTMLElementType::kHTMLFrameSetElement },
        { "h1", HTMLElementType::kHTMLHeadingElement },
        { "h2", HTMLElementType::kHTMLHeadingElement },
        { "h3", HTMLElementType::kHTMLHeadingElement },
        { "h4", HTMLElementType::kHTMLHeadingElement },
        { "h5", HTMLElementType::kHTMLHeadingElement },
        { "h6", HTMLElementType::kHTMLHeadingElement },
        { "head", HTMLElementType::kHTMLHeadElement },
        { "header", HTMLElementType::kHTMLElement },
        { "hgroup", HTMLElementType::kHTMLElement },
        { "hr", HTMLElementType::kHTMLHRElement },
        { "html", HTMLElementType::kHTMLHtmlElement },
        { "i", HTMLElementType::kHTMLElement },
        { "iframe", HTMLElementType::kHTMLIFrameElement },
        { "image", HTMLElementType::kHTMLUnknownElement },
        { "img", HTMLElementType::kHTMLImageElement },
        { "input", HTMLElementType::kHTMLInputElement },
        { "ins", HTMLElementType::kHTMLModElement },
        { "kbd", HTMLElementType::kHTMLElement },
        { "keygen", HTMLElementType::kHTMLUnknownElement },
        { "label", HTMLElementType::kHTMLLabelElement },
        { "layer", HTMLElementType::kHTMLElement },
        { "legend", HTMLElementType::kHTMLLegendElement },
        { "li", HTMLElementType::kHTMLLIElement },
        { "link", HTMLElementType::kHTMLLinkElement },
        { "listing", HTMLElementType::kHTMLPreElement },
        { "main", HTMLElementType::kHTMLElement },
        { "map", HTMLElementType::kHTMLMapElement },
        { "mark", HTMLElementType::kHTMLElement },
        { "marquee", HTMLElementType::kHTMLMarqueeElement },
        { "menu", HTMLElementType::kHTMLMenuElement },
        { "meta", HTMLElementType::kHTMLMetaElement },
        { "meter", HTMLElementType::kHTMLMeterElement },
        { "nav", HTMLElementType::kHTMLElement },
        { "nobr", HTMLElementType::kHTMLElement },
        { "noembed", HTMLElementType::kHTMLElement },
        { "noframes", HTMLElementType::kHTMLElement },
        { "nolayer", HTMLElementType::kHTMLElement },
        { "noscript", HTMLElementType::kHTMLElement },
        { "object", HTMLElementType::kHTMLObjectElement },
        { "ol", HTMLElementType::kHTMLOListElement },
        { "optgroup", HTMLElementType::kHTMLOptGroupElement },
        { "option", HTMLElementType::kHTMLOptionElement },
        { "output", HTMLElementType::kHTMLOutputElement },
        { "p", HTMLElementType::kHTMLParagraphElement },
        { "param", HTMLElementType::kHTMLParamElement },
        { "picture", HTMLElementType::kHTMLPictureElement },
        { "plaintext", HTMLElementType::kHTMLElement },
        { "portal", HTMLElementType::kHTMLPortalElement },
        { "pre", HTMLElementType::kHTMLPreElement },
        { "progress", HTMLElementType::kHTMLProgressElement },
        { "q", HTMLElementType::kHTMLQuoteElement },
        { "rb", HTMLElementType::kHTMLElement },
        { "rp", HTMLElementType::kHTMLElement },
        { "rt", HTMLElementType::kHTMLElement },
        { "rtc", HTMLElementType::kHTMLElement },
        { "ruby", HTMLElementType::kHTMLElement },
        { "s", HTMLElementType::kHTMLElement },
        { "samp", HTMLElementType::kHTMLElement },
        { "script", HTMLElementType::kHTMLScriptElement },
        { "section", HTMLElementType::kHTMLElement },
        { "select", HTMLElementType::kHTMLSelectElement },
        { "selectmenu", HTMLElementType::kHTMLSelectMenuElement },
        { "slot", HTMLElementType::kHTMLSlotElement },
        { "small", HTMLElementType::kHTMLElement },
        { "source", HTMLElementType::kHTMLSourceElement },
        { "span", HTMLElementType::kHTMLSpanElement },
        { "strike", HTMLElementType::kHTMLElement },
        { "strong", HTMLElementType::kHTMLElement },
        { "style", HTMLElementType::kHTMLStyleElement },
        { "sub", HTMLElementType::kHTMLElement },
        { "summary", HTMLElementType::kHTMLElement },
        { "sup", HTMLElementType::kHTMLElement },
        { "table", HTMLElementType::kHTMLTableElement },
        { "tbody", HTMLElementType::kHTMLTableSectionElement },
        { "td", HTMLElementType::kHTMLTableCellElement },
        { "template", HTMLElementType::kHTMLTemplateElement },
        { "textarea", HTMLElementType::kHTMLTextAreaElement },
        { "tfoot", HTMLElementType::kHTMLTableSectionElement },
        { "th", HTMLElementType::kHTMLTableCellElement },
        { "thead", HTMLElementType::kHTMLTableSectionElement },
        { "time", HTMLElementType::kHTMLTimeElement },
        { "title", HTMLElementType::kHTMLTitleElement },
        { "tr", HTMLElementType::kHTMLTableRowElement },
        { "track", HTMLElementType::kHTMLTrackElement },
        { "tt", HTMLElementType::kHTMLElement },
        { "u", HTMLElementType::kHTMLElement },
        { "ul", HTMLElementType::kHTMLUListElement },
        { "var", HTMLElementType::kHTMLElement },
        { "video", HTMLElementType::kHTMLVideoElement },
        { "wbr", HTMLElementType::kHTMLElement },
        { "xmp", HTMLElementType::kHTMLPreElement },
    };
    for (const auto& tag : kTags)
        html_type_map.insert(tag.name, tag.type);
    return html_type_map;
}

static const HTMLTypeMap& GetHTMLTypeMap()
{
    DEFINE_STATIC_LOCAL(const HTMLTypeMap, html_type_map, (CreateHTMLTypeMap()));
    return html_type_map;
}

HTMLElementType htmlElementTypeForTag(const AtomicString& tagName, const Document* document)
{
    const auto& html_type_map = GetHTMLTypeMap();
    auto it = html_type_map.find(tagName);
    if (it == html_type_map.end())
        return HTMLElementType::kHTMLUnknownElement;

    if (tagName == "fencedframe") {
        if (!RuntimeEnabledFeatures::FencedFramesEnabled(document->GetExecutionContext())) {
            return HTMLElementType::kHTMLUnknownElement;
        }
    }
    if (tagName == "portal") {
        if (!RuntimeEnabledFeatures::PortalsEnabled(document->GetExecutionContext())) {
            return HTMLElementType::kHTMLUnknownElement;
        }
    }
    if (tagName == "selectmenu") {
        if (!RuntimeEnabledFeatures::HTMLSelectMenuElementEnabled(document->GetExecutionContext())) {
            return HTMLElementType::kHTMLUnknownElement;
        }
    }
    return it->value;
}

bool IsKnownBuiltinTagName(const AtomicString& tag_name) { return GetHTMLTypeMap().Contains(tag_name); }
} // namespace blink
