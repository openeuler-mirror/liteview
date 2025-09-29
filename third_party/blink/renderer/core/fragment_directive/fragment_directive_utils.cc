// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/fragment_directive/fragment_directive_utils.h"

#include "components/shared_highlighting/core/common/fragment_directives_utils.h"
#include "third_party/blink/renderer/bindings/core/v8/serialization/serialized_script_value.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/loader/document_loader.h"
#include "base/strings/string_split.h"
#include "base/strings/strcat.h"

namespace shared_highlighting {

const char kFragmentsUrlDelimiter[] = ":~:";
const int kFragmentsUrlDelimiterLength = sizeof(kFragmentsUrlDelimiter) - 1;

const char kTextDirectiveParameterName[] = "text=";
const size_t kTextDirectiveParameterNameLength = sizeof(kTextDirectiveParameterName) - 1;

const char kSelectorDirectiveParameterName[] = "selector(";
const int kSelectorDirectiveParameterNameLength = sizeof(kSelectorDirectiveParameterName) - 1;

const char kSelectorJoinDelimeter[] = "&";
const int kSelectorJoinDelimeterLength = sizeof(kSelectorJoinDelimeter) - 1;

GURL RemoveFragmentSelectorDirectives(const GURL& url)
{
    const std::vector<base::StringPiece> directive_parameter_names { kTextDirectiveParameterName, kSelectorDirectiveParameterName };
    size_t start_pos = url.ref().find(kFragmentsUrlDelimiter);
    if (start_pos == std::string::npos)
        return url;

    // Split url before and after the ":~:" delimiter.
    std::string fragment_prefix = url.ref().substr(0, start_pos);
    std::string fragment_directive = url.ref().substr(start_pos + kFragmentsUrlDelimiterLength);

    // Split fragment directive on "&" and remove any piece that starts with
    // one of the directive_parameter_names
    std::vector<std::string> should_keep_directives;
    for (const std::string& directive : base::SplitString(fragment_directive, kSelectorJoinDelimeter, base::TRIM_WHITESPACE, base::SPLIT_WANT_ALL)) {
        if (base::ranges::none_of(directive_parameter_names,
                [&directive](const base::StringPiece& directive_parameter_name) { return base::StartsWith(directive, directive_parameter_name); })) {
            should_keep_directives.push_back(directive);
        }
    }

    // Join remaining pieces and append to the url.
    std::string new_fragment = should_keep_directives.empty()
        ? fragment_prefix
        : base::StrCat({ fragment_prefix, kFragmentsUrlDelimiter, base::JoinString(should_keep_directives, kSelectorJoinDelimeter) });

    GURL::Replacements replacements;
    if (new_fragment.empty())
        replacements.ClearRef();
    else
        replacements.SetRefStr(new_fragment);
    return url.ReplaceComponents(replacements);
}

}

namespace blink {

// static
void FragmentDirectiveUtils::RemoveSelectorsFromUrl(LocalFrame* frame)
{
    KURL url(shared_highlighting::RemoveFragmentSelectorDirectives(GURL(frame->Loader().GetDocumentLoader()->GetHistoryItem()->Url())));

    // Replace the current history entry with the new url, so that the text
    // fragment shown in the URL matches the state of the highlight on the page.
    // This is equivalent to history.replaceState in javascript.
    frame->DomWindow()->document()->Loader()->RunURLAndHistoryUpdateSteps(url, nullptr, mojom::blink::SameDocumentNavigationType::kFragment,
        /*data=*/nullptr, WebFrameLoadType::kReplaceCurrentItem);
}

} // namespace blink
