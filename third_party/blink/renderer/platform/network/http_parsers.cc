/*
 * Copyright (C) 2006 Alexey Proskuryakov (ap@webkit.org)
 * Copyright (C) 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Torch Mobile Inc. http://www.torchmobile.com/
 * Copyright (C) 2009 Google Inc. All rights reserved.
 * Copyright (C) 2011 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "third_party/blink/renderer/platform/network/http_parsers.h"

#include <memory>
#include <string>
#include <utility>

#include "base/containers/flat_map.h"
#include "net/http/http_content_disposition.h"
#include "net/http/http_response_headers.h"
#include "net/http/http_util.h"
#include "services/network/public/cpp/content_security_policy/content_security_policy.h"
#include "services/network/public/cpp/parsed_headers.h"
#include "services/network/public/cpp/timing_allow_origin_parser.h"
#include "services/network/public/mojom/parsed_headers.mojom-blink.h"
#include "services/network/public/mojom/supports_loading_mode.mojom-blink.h"
#include "services/network/public/mojom/timing_allow_origin.mojom-blink.h"
#include "third_party/abseil-cpp/absl/types/optional.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/renderer/platform/loader/fetch/resource_response.h"
#include "third_party/blink/renderer/platform/network/header_field_tokenizer.h"
#include "third_party/blink/renderer/platform/network/http_names.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/date_math.h"
#include "third_party/blink/renderer/platform/wtf/math_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/wtf/text/character_names.h"
#include "third_party/blink/renderer/platform/wtf/text/parsing_utilities.h"
#include "third_party/blink/renderer/platform/wtf/text/string_builder.h"
#include "third_party/blink/renderer/platform/wtf/text/string_utf8_adaptor.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/wtf.h"

#include <sstream>
#include <string>

#include "base/base64url.h"
#include "base/containers/contains.h"
#include "base/containers/flat_set.h"
#include "base/feature_list.h"
#include "base/ranges/algorithm.h"
#include "base/strings/strcat.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_piece.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include "base/strings/stringprintf.h"
#include "base/strings/utf_string_conversions.h"
#include "net/http/http_response_headers.h"
#include "services/network/public/cpp/content_security_policy/csp_context.h"
#include "services/network/public/cpp/content_security_policy/csp_source.h"
#include "services/network/public/cpp/content_security_policy/csp_source_list.h"
#include "services/network/public/cpp/features.h"
#include "services/network/public/cpp/is_potentially_trustworthy.h"
#include "services/network/public/cpp/web_sandbox_flags.h"
#include "services/network/public/mojom/content_security_policy.mojom.h"
#include "url/gurl.h"
#include "url/origin.h"
#include "url/url_canon.h"
#include "url/url_util.h"

// We would like finding a way to convert from/to blink type automatically.
// The following attempt has been withdrawn:
// https://chromium-review.googlesource.com/c/chromium/src/+/2126933/7
//
// Note: nesting these helpers inside network::mojom bypasses warnings from
// audit_non_blink_style.py, as well as saving a bunch of typing to qualify the
// types below.
namespace network {

// using CSPDirectiveName = mojom::CSPDirectiveName;
// using DirectivesMap = std::vector<std::pair<base::StringPiece, base::StringPiece>>;
// 
// // Parses a "Content-Security-Policy" header.
// // Returns a map to the directives found.
// DirectivesMap ParseHeaderValue(base::StringPiece header) 
// {
//     DirectivesMap result;
// 
//     // For each token returned by strictly splitting serialized on the
//     // U+003B SEMICOLON character (;):
//     // 1. Strip leading and trailing ASCII whitespace from token.
//     // 2. If token is an empty string, continue.
//     for (const auto& directive : base::SplitStringPiece(header, ";", base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY)) {
//         // 3. Let directive name be the result of collecting a sequence of
//         // code points from token which are not ASCII whitespace.
//         // 4. Set directive name to be the result of running ASCII lowercase
//         // on directive name.
//         size_t pos = directive.find_first_of(base::kWhitespaceASCII);
//         base::StringPiece name = directive.substr(0, pos);
// 
//         // 5. Let directive value be the result of splitting token on ASCII
//         // whitespace.
//         base::StringPiece value;
//         if (pos != std::string::npos) {
//             value = base::TrimString(directive.substr(pos + 1), base::kWhitespaceASCII, base::TRIM_ALL);
//         }
// 
//         // 6. Let directive be a new directive whose name is directive name,
//         // and value is directive value.
//         // 7. Append directive to policy's directive set.
//         result.emplace_back(std::make_pair(name, value));
//     }
// 
//     return result;
// }
// 
// mojom::CSPSourcePtr ComputeSelfOrigin(const GURL& url) 
// {
//     if (url.scheme() == url::kFileScheme) {
//         // Forget the host for file schemes. Host can anyway only be `localhost` or
//         // empty and this is platform dependent.
//         //
//         // TODO(antoniosartori): Consider returning mojom::CSPSource::New() for
//         // file: urls, so that 'self' for file: would match nothing.
//         return mojom::CSPSource::New(url::kFileScheme, "", url::PORT_UNSPECIFIED, "", false, false);
//     }
//     return mojom::CSPSource::New(url.scheme(), url.host(), url.EffectiveIntPort(), "", false, false);
// }
// 
// bool IsDirectiveNameCharacter(char c)
// {
//     return base::IsAsciiAlpha(c) || c == '-';
// }
// 
// bool IsDirectiveValueCharacter(char c) 
// {
//     // Whitespace + VCHAR, but not ',' and ';'
//     return base::IsAsciiWhitespace(c) || (base::IsAsciiPrintable(c) && c != ',' && c != ';');
// }
// 
// std::string UnrecognizedDirectiveErrorMessage(const std::string& directive_name)
// {
//     if (base::EqualsCaseInsensitiveASCII(directive_name, "allow")) {
//         return "The 'allow' directive has been replaced with 'default-src'. Please "
//             "use that directive instead, as 'allow' has no effect.";
//     }
// 
//     if (base::EqualsCaseInsensitiveASCII(directive_name, "options")) {
//         return "The 'options' directive has been replaced with the 'unsafe-inline' "
//             "and 'unsafe-eval' source expressions for the 'script-src' and "
//             "'style-src' directives. Please use those directives instead, as "
//             "'options' has no effect.";
//     }
// 
//     if (base::EqualsCaseInsensitiveASCII(directive_name, "policy-uri")) {
//         return "The 'policy-uri' directive has been removed from the "
//             "specification. Please specify a complete policy via the "
//             "Content-Security-Policy header.";
//     }
// 
//     if (base::EqualsCaseInsensitiveASCII(directive_name, "plugin-types")) {
//         return "The Content-Security-Policy directive 'plugin-types' has been "
//             "removed from the specification. If you want to block plugins, "
//             "consider specifying \"object-src 'none'\" instead.";
//     }
// 
//     return base::StringPrintf("Unrecognized Content-Security-Policy directive '%s'.", directive_name.c_str());
// }
// 
// bool SupportedInReportOnly(CSPDirectiveName directive) 
// {
//     switch (directive) {
//     case CSPDirectiveName::Sandbox:
//     case CSPDirectiveName::UpgradeInsecureRequests:
//     case CSPDirectiveName::TreatAsPublicAddress:
//         return false;
// 
//     case CSPDirectiveName::BaseURI:
//     case CSPDirectiveName::BlockAllMixedContent:
//     case CSPDirectiveName::ChildSrc:
//     case CSPDirectiveName::ConnectSrc:
//     case CSPDirectiveName::DefaultSrc:
//     case CSPDirectiveName::FencedFrameSrc:
//     case CSPDirectiveName::FontSrc:
//     case CSPDirectiveName::FormAction:
//     case CSPDirectiveName::FrameAncestors:
//     case CSPDirectiveName::FrameSrc:
//     case CSPDirectiveName::ImgSrc:
//     case CSPDirectiveName::ManifestSrc:
//     case CSPDirectiveName::MediaSrc:
//     case CSPDirectiveName::NavigateTo:
//     case CSPDirectiveName::ObjectSrc:
//     case CSPDirectiveName::PrefetchSrc:
//     case CSPDirectiveName::ReportTo:
//     case CSPDirectiveName::ReportURI:
//     case CSPDirectiveName::RequireTrustedTypesFor:
//     case CSPDirectiveName::ScriptSrc:
//     case CSPDirectiveName::ScriptSrcAttr:
//     case CSPDirectiveName::ScriptSrcElem:
//     case CSPDirectiveName::StyleSrc:
//     case CSPDirectiveName::StyleSrcAttr:
//     case CSPDirectiveName::StyleSrcElem:
//     case CSPDirectiveName::TrustedTypes:
//     case CSPDirectiveName::Unknown:
//     case CSPDirectiveName::WorkerSrc:
//         return true;
//     };
//     return false;
// }
// 
// bool IsBase64Char(char c) 
// {
//     return base::IsAsciiAlpha(c) || base::IsAsciiDigit(c) || c == '+' ||
//         c == '-' || c == '_' || c == '/';
// }
// 
// int EatChar(const char** it, const char* end, bool (*predicate)(char)) 
// {
//     int count = 0;
//     while (*it != end) {
//         if (!predicate(**it))
//             break;
//         ++count;
//         ++(*it);
//     }
//     return count;
// }
// 
// struct SupportedPrefixesStruct {
//     const char* prefix;
//     int prefix_length;
//     mojom::CSPHashAlgorithm type;
// };
// 
// // Checks whether |expression| is a valid base64-encoded string.
// // Cf. https://w3c.github.io/webappsec-csp/#framework-directive-source-list.
// bool IsBase64(base::StringPiece expression)
// {
//     if (expression.empty())
//         return false;
// 
//     auto* it = expression.begin();
//     auto* end = expression.end();
// 
//     int count_1 = EatChar(&it, end, IsBase64Char);
//     int count_2 = EatChar(&it, end, [](char c) -> bool { return c == '='; });
// 
//     // At least one non '=' char at the beginning, at most two '=' at the end.
//     return count_1 >= 1 && count_2 <= 2 && it == end;
// }
// 
// // Parse a hash-source, return false on error.
// bool ParseHash(base::StringPiece expression, mojom::CSPHashSource* hash) {
//     static const SupportedPrefixesStruct SupportedPrefixes[] = {
//         {"'sha256-", 8, mojom::CSPHashAlgorithm::SHA256},
//         {"'sha384-", 8, mojom::CSPHashAlgorithm::SHA384},
//         {"'sha512-", 8, mojom::CSPHashAlgorithm::SHA512},
//         {"'sha-256-", 9, mojom::CSPHashAlgorithm::SHA256},
//         {"'sha-384-", 9, mojom::CSPHashAlgorithm::SHA384},
//         {"'sha-512-", 9, mojom::CSPHashAlgorithm::SHA512} };
// 
//     for (auto item : SupportedPrefixes) {
//         if (base::StartsWith(expression, item.prefix,
//             base::CompareCase::INSENSITIVE_ASCII)) {
//             base::StringPiece subexpression = expression.substr(
//                 item.prefix_length, expression.length() - item.prefix_length - 1);
//             if (!IsBase64(subexpression))
//                 return false;
// 
//             if (expression[expression.length() - 1] != '\'')
//                 return false;
// 
//             hash->algorithm = item.type;
// 
//             // We lazily accept both base64url and base64-encoded data.
//             std::string normalized_value;
//             base::ReplaceChars(subexpression, "+", "-", &normalized_value);
//             base::ReplaceChars(normalized_value, "/", "_", &normalized_value);
// 
//             std::string out;
//             if (!base::Base64UrlDecode(normalized_value, base::Base64UrlDecodePolicy::IGNORE_PADDING, &out))
//                 return false;
//             hash->value = std::vector<uint8_t>(out.begin(), out.end());
//             return true;
//         }
//     }
// 
//     return false;
// }
// 
// // Parse a nonce-source, return false on error.
// bool ParseNonce(base::StringPiece expression, std::string* nonce) 
// {
//     if (!base::StartsWith(expression, "'nonce-", base::CompareCase::INSENSITIVE_ASCII)) {
//         return false;
//     }
// 
//     base::StringPiece subexpression = expression.substr(7, expression.length() - 8);
// 
//     if (!IsBase64(subexpression))
//         return false;
// 
//     if (expression[expression.length() - 1] != '\'') {
//         return false;
//     }
// 
//     *nonce = std::string(subexpression);
//     return true;
// }
// 
// // https://www.w3.org/TR/CSP3/#grammardef-scheme-part
// bool ParseScheme(base::StringPiece scheme, mojom::CSPSource* csp_source)
// {
//     if (scheme.empty())
//         return false;
// 
//     if (!base::IsAsciiAlpha(scheme[0]))
//         return false;
// 
//     auto is_scheme_character = [](auto c) {
//         return base::IsAsciiAlpha(c) || base::IsAsciiDigit(c) || c == '+' ||
//             c == '-' || c == '.';
//     };
// 
//     if (!std::all_of(scheme.begin() + 1, scheme.end(), is_scheme_character))
//         return false;
// 
//     csp_source->scheme = std::string(scheme);
// 
//     return true;
// }
// 
// // https://www.w3.org/TR/CSP3/#grammardef-host-part
// bool ParseHost(base::StringPiece host, mojom::CSPSource* csp_source)
// {
//     if (host.size() == 0)
//         return false;
// 
//     // * || *.
//     if (host[0] == '*') {
//         if (host.size() == 1) {
//             csp_source->is_host_wildcard = true;
//             return true;
//         }
// 
//         if (host[1] != '.')
//             return false;
// 
//         csp_source->is_host_wildcard = true;
//         host = host.substr(2);
//     }
// 
//     if (host.empty())
//         return false;
// 
//     for (const base::StringPiece& piece : base::SplitStringPiece(
//         host, ".", base::KEEP_WHITESPACE, base::SPLIT_WANT_ALL)) {
//         if (piece.empty() || !base::ranges::all_of(piece, [](auto c) {
//             return base::IsAsciiAlpha(c) || base::IsAsciiDigit(c) || c == '-';
//             }))
//             return false;
//     }
//     csp_source->host = std::string(host);
// 
//     return true;
// }
// 
// // https://www.w3.org/TR/CSP3/#grammardef-port-part
// bool ParsePort(base::StringPiece port, mojom::CSPSource* csp_source)
// {
//     if (port.empty())
//         return false;
// 
//     if (base::EqualsCaseInsensitiveASCII(port, "*")) {
//         csp_source->is_port_wildcard = true;
//         return true;
//     }
// 
//     if (!base::ranges::all_of(
//         port, base::IsAsciiDigit<base::StringPiece::value_type>)) {
//         return false;
//     }
// 
//     return base::StringToInt(port, &csp_source->port);
// }
// 
// // https://www.w3.org/TR/CSP3/#grammardef-path-part
// bool ParsePath(base::StringPiece path, mojom::CSPSource* csp_source) 
// {
//     DCHECK_NE(0U, path.size());
//     if (path[0] != '/')
//         return false;
// 
//     url::RawCanonOutputT<char16_t> unescaped;
//     url::DecodeURLEscapeSequences(path.data(), path.size(),
//         url::DecodeURLMode::kUTF8OrIsomorphic,
//         &unescaped);
//     base::UTF16ToUTF8(unescaped.data(), unescaped.length(), &csp_source->path);
// 
//     return true;
// }
// 
// // This implements tt-policy-name from
// // https://w3c.github.io/webappsec-trusted-types/dist/spec/#trusted-types-csp-directive/
// bool IsValidTrustedTypesPolicyName(base::StringPiece value) {
//     return base::ranges::all_of(value, [](char c) {
//         return base::IsAsciiAlpha(c) || base::IsAsciiDigit(c) ||
//         base::Contains("-#=_/@.%", c);
//         });
// }
// 
// // Parse the 'trusted-types' directive.
// // https://w3c.github.io/webappsec-trusted-types/dist/spec/#trusted-types-csp-directive
// network::mojom::CSPTrustedTypesPtr ParseTrustedTypes(
//     base::StringPiece value,
//     std::vector<std::string>& parsing_errors) 
// {
//     auto out = network::mojom::CSPTrustedTypes::New();
//     std::vector<base::StringPiece> pieces =
//         base::SplitStringPiece(value, base::kWhitespaceASCII, base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY);
// 
//     if (pieces.size() == 1 && pieces[0] == "'none'")
//         return out;
// 
//     for (const auto expression : pieces) {
//         if (expression == "*")
//             out->allow_any = true;
//         else if (expression == "'allow-duplicates'")
//             out->allow_duplicates = true;
//         else if (expression == "'none'") {
//             parsing_errors.emplace_back(
//                 "The value of the Content Security Policy directive "
//                 "'trusted_types' contains an invalid policy: 'none'. "
//                 "It will be ignored. "
//                 "Note that 'none' has no effect unless it is the only "
//                 "expression in the directive value.");
//         } else if (IsValidTrustedTypesPolicyName(expression))
//             out->list.emplace_back(expression);
//         else {
//             parsing_errors.emplace_back(base::StringPrintf(
//                 "The value of the Content Security Policy directive "
//                 "'trusted_types' contains an invalid policy: '%s'. "
//                 "It will be ignored.",
//                 std::string(expression).c_str()));
//         }
//     }
//     return out;
// }
// 
// std::string ToString(CSPDirectiveName name) 
// {
//     switch (name) {
//     case CSPDirectiveName::BaseURI:
//         return "base-uri";
//     case CSPDirectiveName::BlockAllMixedContent:
//         return "block-all-mixed-content";
//     case CSPDirectiveName::ChildSrc:
//         return "child-src";
//     case CSPDirectiveName::ConnectSrc:
//         return "connect-src";
//     case CSPDirectiveName::DefaultSrc:
//         return "default-src";
//     case CSPDirectiveName::FencedFrameSrc:
//         return "fenced-frame-src";
//     case CSPDirectiveName::FrameAncestors:
//         return "frame-ancestors";
//     case CSPDirectiveName::FrameSrc:
//         return "frame-src";
//     case CSPDirectiveName::FontSrc:
//         return "font-src";
//     case CSPDirectiveName::FormAction:
//         return "form-action";
//     case CSPDirectiveName::ImgSrc:
//         return "img-src";
//     case CSPDirectiveName::ManifestSrc:
//         return "manifest-src";
//     case CSPDirectiveName::MediaSrc:
//         return "media-src";
//     case CSPDirectiveName::ObjectSrc:
//         return "object-src";
//     case CSPDirectiveName::PrefetchSrc:
//         return "prefetch-src";
//     case CSPDirectiveName::ReportURI:
//         return "report-uri";
//     case CSPDirectiveName::RequireTrustedTypesFor:
//         return "require-trusted-types-for";
//     case CSPDirectiveName::Sandbox:
//         return "sandbox";
//     case CSPDirectiveName::ScriptSrc:
//         return "script-src";
//     case CSPDirectiveName::ScriptSrcAttr:
//         return "script-src-attr";
//     case CSPDirectiveName::ScriptSrcElem:
//         return "script-src-elem";
//     case CSPDirectiveName::StyleSrc:
//         return "style-src";
//     case CSPDirectiveName::StyleSrcAttr:
//         return "style-src-attr";
//     case CSPDirectiveName::StyleSrcElem:
//         return "style-src-elem";
//     case CSPDirectiveName::UpgradeInsecureRequests:
//         return "upgrade-insecure-requests";
//     case CSPDirectiveName::TreatAsPublicAddress:
//         return "treat-as-public-address";
//     case CSPDirectiveName::TrustedTypes:
//         return "trusted-types";
//     case CSPDirectiveName::WorkerSrc:
//         return "worker-src";
//     case CSPDirectiveName::ReportTo:
//         return "report-to";
//     case CSPDirectiveName::NavigateTo:
//         return "navigate-to";
//     case CSPDirectiveName::Unknown:
//         return "";
//     }
//     NOTREACHED();
//     return "";
// }
// 
// // Parses a CSP source expression.
// // https://w3c.github.io/webappsec-csp/#source-lists
// //
// // Return false on errors.
// // Adds parsing error messages to |parsing_errors|.
// // Notice that this can return true and still add some parsing error message
// // (for example, if there is a url with a non-empty query part).
// bool ParseSource(CSPDirectiveName directive_name,
//     base::StringPiece expression,
//     mojom::CSPSource* csp_source,
//     std::vector<std::string>& parsing_errors) 
// {
//     size_t position = expression.find_first_of(":/");
//     if (position != std::string::npos && expression[position] == ':') {
//         // scheme:
//         //       ^
//         if (position + 1 == expression.size())
//             return ParseScheme(expression.substr(0, position), csp_source);
// 
//         if (expression[position + 1] == '/') {
//             // scheme://
//             //       ^
//             if (position + 2 >= expression.size() || expression[position + 2] != '/')
//                 return false;
//             if (!ParseScheme(expression.substr(0, position), csp_source))
//                 return false;
//             expression = expression.substr(position + 3);
//             position = expression.find_first_of(":/");
//         }
//     }
// 
//     // host
//     //     ^
//     if (!ParseHost(expression.substr(0, position), csp_source))
//         return false;
// 
//     // If there's nothing more to parse (no port or path specified), return.
//     if (position == std::string::npos)
//         return true;
// 
//     expression = expression.substr(position);
// 
//     // :\d*
//     // ^
//     if (expression[0] == ':') {
//         size_t port_end = expression.find_first_of("/");
//         base::StringPiece port = expression.substr(
//             1, port_end == std::string::npos ? std::string::npos : port_end - 1);
//         if (!ParsePort(port, csp_source))
//             return false;
//         if (port_end == std::string::npos)
//             return true;
// 
//         expression = expression.substr(port_end);
//     }
// 
//     // /
//     // ^
//     if (expression.empty())
//         return true;
// 
//     // Emit a warning to the user when a url contains a # or ?.
//     position = expression.find_first_of("#?");
//     bool path_parsed = ParsePath(expression.substr(0, position), csp_source);
//     if (path_parsed && position != std::string::npos) {
//         const char* ignoring =
//             expression[position] == '?'
//             ? "The query component, including the '?', will be ignored."
//             : "The fragment identifier, including the '#', will be ignored.";
//         parsing_errors.emplace_back(base::StringPrintf(
//             "The source list for Content Security Policy directive '%s' "
//             "contains a source with an invalid path: '%s'. %s",
//             ToString(directive_name).c_str(), std::string(expression).c_str(),
//             ignoring));
//     }
// 
//     return path_parsed;
// }
// 
// CSPDirectiveName ToCSPDirectiveName(const std::string& name)
// {
//     if (base::EqualsCaseInsensitiveASCII(name, "base-uri")) {
//         return CSPDirectiveName::BaseURI;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "block-all-mixed-content")) {
//         return CSPDirectiveName::BlockAllMixedContent;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "child-src")) {
//         return CSPDirectiveName::ChildSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "connect-src")) {
//         return CSPDirectiveName::ConnectSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "default-src")) {
//         return CSPDirectiveName::DefaultSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "fenced-frame-src")) {
//         return CSPDirectiveName::FencedFrameSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "frame-ancestors")) {
//         return CSPDirectiveName::FrameAncestors;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "frame-src")) {
//         return CSPDirectiveName::FrameSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "font-src")) {
//         return CSPDirectiveName::FontSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "form-action")) {
//         return CSPDirectiveName::FormAction;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "img-src")) {
//         return CSPDirectiveName::ImgSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "manifest-src")) {
//         return CSPDirectiveName::ManifestSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "media-src")) {
//         return CSPDirectiveName::MediaSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "object-src")) {
//         return CSPDirectiveName::ObjectSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "prefetch-src")) {
//         return CSPDirectiveName::PrefetchSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "report-uri")) {
//         return CSPDirectiveName::ReportURI;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "require-trusted-types-for")) {
//         return CSPDirectiveName::RequireTrustedTypesFor;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "sandbox")) {
//         return CSPDirectiveName::Sandbox;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "script-src")) {
//         return CSPDirectiveName::ScriptSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "script-src-attr")) {
//         return CSPDirectiveName::ScriptSrcAttr;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "script-src-elem")) {
//         return CSPDirectiveName::ScriptSrcElem;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "style-src")) {
//         return CSPDirectiveName::StyleSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "style-src-attr")) {
//         return CSPDirectiveName::StyleSrcAttr;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "style-src-elem")) {
//         return CSPDirectiveName::StyleSrcElem;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "treat-as-public-address")) {
//         return CSPDirectiveName::TreatAsPublicAddress;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "trusted-types")) {
//         return CSPDirectiveName::TrustedTypes;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "upgrade-insecure-requests")) {
//         return CSPDirectiveName::UpgradeInsecureRequests;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "worker-src")) {
//         return CSPDirectiveName::WorkerSrc;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "report-to")) {
//         return CSPDirectiveName::ReportTo;
//     }
//     if (base::EqualsCaseInsensitiveASCII(name, "navigate-to")) {
//         return CSPDirectiveName::NavigateTo;
//     }
// 
//     return CSPDirectiveName::Unknown;
// }
// 
// // Parse source-list grammar.
// // https://www.w3.org/TR/CSP3/#grammardef-serialized-source-list
// // Append parsing errors to |parsing_errors|.
// mojom::CSPSourceListPtr ParseSourceList(
//     CSPDirectiveName directive_name,
//     base::StringPiece directive_value,
//     std::vector<std::string>& parsing_errors) 
// {
//     base::StringPiece value =
//         base::TrimString(directive_value, base::kWhitespaceASCII, base::TRIM_ALL);
// 
//     auto directive = mojom::CSPSourceList::New();
// 
//     if (base::EqualsCaseInsensitiveASCII(value, "'none'"))
//         return directive;
// 
//     std::vector<base::StringPiece> tokens = base::SplitStringPiece(value, base::kWhitespaceASCII, base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY);
// 
//     bool contains_none = false;
// 
//     for (const auto& expression : tokens) {
//         if (base::EqualsCaseInsensitiveASCII(expression, "'none'")) {
//             contains_none = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'self'")) {
//             directive->allow_self = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "*")) {
//             directive->allow_star = true;
//             continue;
//         }
// 
//         if (ToCSPDirectiveName(std::string(expression)) != CSPDirectiveName::Unknown) {
//             parsing_errors.emplace_back(base::StringPrintf(
//                 "The Content-Security-Policy directive '%s' contains '%s' as a "
//                 "source expression. Did you want to add it as a directive and forget "
//                 "a semicolon?",
//                 ToString(directive_name).c_str(), std::string(expression).c_str()));
//         }
// 
//         auto csp_source = mojom::CSPSource::New();
//         if (ParseSource(directive_name, expression, csp_source.get(),
//             parsing_errors)) {
//             directive->sources.push_back(std::move(csp_source));
//             continue;
//         }
// 
//         if (directive_name == CSPDirectiveName::FrameAncestors) {
//             // The frame-ancestors directive does not support anything else
//             // https://w3c.github.io/webappsec-csp/#directive-frame-ancestors
//             parsing_errors.emplace_back(base::StringPrintf(
//                 "The Content-Security-Policy directive 'frame-ancestors' does not "
//                 "support the source expression '%s'",
//                 std::string(expression).c_str()));
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'unsafe-inline'")) {
//             directive->allow_inline = true;
//             continue;
//         }
// 
//         // Discussed at https://github.com/WICG/nav-speculation/pull/209, and merged
//         // to the speculationrules explainer,
//         // https://github.com/WICG/nav-speculation/blob/main/triggers.md#content-security-policy.
//         // TODO(https://crbug.com/1382361): Have a patch spec and merge it to the
//         // upstream CSP spec.
//         if (//base::FeatureList::IsEnabled(features::kPrerender2ContentSecurityPolicyExtensions) &&
//             base::EqualsCaseInsensitiveASCII(expression, "'inline-speculation-rules'")) {
//             if (directive_name == CSPDirectiveName::ScriptSrc ||
//                 directive_name == CSPDirectiveName::ScriptSrcElem) {
//                 //directive->allow_inline_speculation_rules = true;
//                 continue;
//             } else {
//                 parsing_errors.emplace_back(base::StringPrintf(
//                     "The Content-Security-Policy directive '%s' contains '%s' as a "
//                     "source expression that is permitted only for 'script-src' and "
//                     "'script-src-elem' directives. It will be ignored.",
//                     ToString(directive_name).c_str(), std::string(expression).c_str()));
//                 continue;
//             }
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'unsafe-eval'")) {
//             directive->allow_eval = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'wasm-eval'")) {
//             directive->allow_wasm_eval = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'wasm-unsafe-eval'")) {
//             directive->allow_wasm_unsafe_eval = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression,
//             "'unsafe-allow-redirects'") &&
//             directive_name == CSPDirectiveName::NavigateTo) {
//             directive->allow_response_redirects = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'strict-dynamic'")) {
//             directive->allow_dynamic = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'unsafe-hashes'")) {
//             directive->allow_unsafe_hashes = true;
//             continue;
//         }
// 
//         if (base::EqualsCaseInsensitiveASCII(expression, "'report-sample'")) {
//             directive->report_sample = true;
//             continue;
//         }
// 
//         std::string nonce;
//         if (ParseNonce(expression, &nonce)) {
//             directive->nonces.push_back(std::move(nonce));
//             continue;
//         }
// 
//         auto hash = mojom::CSPHashSource::New();
//         if (ParseHash(expression, hash.get())) {
//             directive->hashes.push_back(std::move(hash));
//             continue;
//         }
// 
//         // Parsing error.
//         // Ignore this source-expression.
//         parsing_errors.emplace_back(base::StringPrintf(
//             "The source list for the Content Security Policy directive '%s' "
//             "contains an invalid source: '%s'. It will be ignored.",
//             ToString(directive_name).c_str(), std::string(expression).c_str()));
//     }
// 
//     if (contains_none &&
//         base::ranges::any_of(tokens, [](const auto& token) -> bool {
//             return !base::EqualsCaseInsensitiveASCII(token, "'report-sample'") &&
//             !base::EqualsCaseInsensitiveASCII(token, "'none'");
//             })) {
//         parsing_errors.emplace_back(base::StringPrintf(
//             "The Content-Security-Policy directive '%s' contains the keyword "
//             "'none' alongside with other source expressions. The keyword 'none' "
//             "must be the only source expression in the directive value, "
//             "otherwise it is ignored.",
//             ToString(directive_name).c_str()));
//     }
// 
//     return directive;
// }
// 
// bool SupportedInMeta(CSPDirectiveName directive)
// {
//     switch (directive) {
//     case CSPDirectiveName::FrameAncestors:
//     case CSPDirectiveName::ReportURI:
//     case CSPDirectiveName::Sandbox:
//     case CSPDirectiveName::TreatAsPublicAddress:
//         return false;
// 
//     case CSPDirectiveName::BaseURI:
//     case CSPDirectiveName::BlockAllMixedContent:
//     case CSPDirectiveName::ChildSrc:
//     case CSPDirectiveName::ConnectSrc:
//     case CSPDirectiveName::DefaultSrc:
//     case CSPDirectiveName::FencedFrameSrc:
//     case CSPDirectiveName::FontSrc:
//     case CSPDirectiveName::FormAction:
//     case CSPDirectiveName::FrameSrc:
//     case CSPDirectiveName::ImgSrc:
//     case CSPDirectiveName::ManifestSrc:
//     case CSPDirectiveName::MediaSrc:
//     case CSPDirectiveName::NavigateTo:
//     case CSPDirectiveName::ObjectSrc:
//     case CSPDirectiveName::PrefetchSrc:
//     case CSPDirectiveName::ReportTo:
//     case CSPDirectiveName::RequireTrustedTypesFor:
//     case CSPDirectiveName::ScriptSrc:
//     case CSPDirectiveName::ScriptSrcAttr:
//     case CSPDirectiveName::ScriptSrcElem:
//     case CSPDirectiveName::StyleSrc:
//     case CSPDirectiveName::StyleSrcAttr:
//     case CSPDirectiveName::StyleSrcElem:
//     case CSPDirectiveName::TrustedTypes:
//     case CSPDirectiveName::Unknown:
//     case CSPDirectiveName::UpgradeInsecureRequests:
//     case CSPDirectiveName::WorkerSrc:
//         return true;
//     };
//     return false;
// }
// 
// void WarnIfDirectiveValueNotEmpty(const std::pair<base::StringPiece, base::StringPiece>& directive, std::vector<std::string>& parsing_errors) 
// {
//     if (!directive.second.empty()) {
//         parsing_errors.emplace_back(base::StringPrintf(
//             "The Content Security Policy directive '%s' should be empty, but was "
//             "delivered with a value of '%s'. The directive has been applied, and "
//             "the value ignored.",
//             std::string(directive.first).c_str(),
//             std::string(directive.second).c_str()));
//     }
// }
// 
// // Parse the 'required-trusted-types-for' directive.
// // https://w3c.github.io/webappsec-trusted-types/dist/spec/#require-trusted-types-for-csp-directive
// network::mojom::CSPRequireTrustedTypesFor ParseRequireTrustedTypesFor(
//     base::StringPiece value,
//     std::vector<std::string>& parsing_errors)
// {
//     network::mojom::CSPRequireTrustedTypesFor out = network::mojom::CSPRequireTrustedTypesFor::None;
//     for (const auto expression : base::SplitStringPiece(
//         value, base::kWhitespaceASCII, base::TRIM_WHITESPACE,
//         base::SPLIT_WANT_NONEMPTY)) {
//         if (expression == "'script'") {
//             out = network::mojom::CSPRequireTrustedTypesFor::Script;
//         } else {
//             const char* hint = nullptr;
//             if (expression == "script" || expression == "scripts" ||
//                 expression == "'scripts'") {
//                 hint = " Did you mean 'script'?";
//             }
// 
//             parsing_errors.emplace_back(base::StringPrintf(
//                 "Invalid expression in 'require-trusted-types-for' "
//                 "Content Security Policy directive: %s.%s\n",
//                 std::string(expression).c_str(), hint));
//         }
//     }
//     if (out == network::mojom::CSPRequireTrustedTypesFor::None)
//         parsing_errors.emplace_back(base::StringPrintf(
//             "'require-trusted-types-for' Content Security Policy "
//             "directive is empty; The directive has no effect.\n"));
//     return out;
// }
// 
// 
// // Parses a reporting directive.
// // https://w3c.github.io/webappsec-csp/#directives-reporting
// void ParseReportDirective(const GURL& request_url,
//     base::StringPiece value,
//     bool using_reporting_api,
//     std::vector<std::string>* report_endpoints,
//     std::vector<std::string>& parsing_errors) {
//     std::vector<base::StringPiece> values =
//         base::SplitStringPiece(value, base::kWhitespaceASCII,
//             base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY);
// 
//     if (using_reporting_api && values.size() > 1) {
//         parsing_errors.emplace_back(
//             "The Content Security Policy directive 'report-to' contains more than "
//             "one endpoint. Only the first one will be used, the other ones will be "
//             "ignored.");
//     }
// 
//     for (const auto& uri : values) {
//         // There are two types of reporting directive:
//         //
//         // - "report-uri (uri)+"
//         //   |uri| must be resolved relatively to the requested URL.
//         //
//         // - "report-to (endpoint)+"
//         //   |endpoint| is an arbitrary string. It refers to an endpoint declared in
//         //   the "Report-To" header. See https://w3c.github.io/reporting
//         if (using_reporting_api) {
//             report_endpoints->push_back(std::string(uri));
// 
//             // 'report-to' only allows for a single token.
//             break;
//         } else {
//             GURL url = request_url.Resolve(uri);
// 
//             if (request_url.SchemeIs(url::kHttpsScheme) &&
//                 !IsUrlPotentiallyTrustworthy(url)) {
//                 parsing_errors.emplace_back(base::StringPrintf(
//                     "The Content Security Policy directive 'report-uri' specifies as "
//                     "endpoint '%s'. This endpoint will be ignored since it violates "
//                     "the policy for Mixed Content.",
//                     std::string(uri).c_str()));
//                 continue;
//             }
// 
//             if (!url.is_valid()) {
//                 parsing_errors.emplace_back(base::StringPrintf(
//                     "The Content Security Policy directive 'report-uri' specifies an "
//                     "invalid endpoint '%s'. It will be ignored.",
//                     std::string(uri).c_str()));
//                 continue;
//             }
//             report_endpoints->push_back(url.spec());
//         }
//     }
// }
// 
// void AddContentSecurityPolicyFromHeader(
//     base::StringPiece header,
//     mojom::ContentSecurityPolicyType type,
//     mojom::ContentSecurityPolicySource source,
//     const GURL& base_url,
//     mojom::ContentSecurityPolicyPtr& out) 
// {
//     DirectivesMap directives = ParseHeaderValue(header);
//     out->header = mojom::ContentSecurityPolicyHeader::New(std::string(header), type, source);
//     out->self_origin = ComputeSelfOrigin(base_url);
// 
//     for (auto directive : directives) {
//         if (!base::ranges::all_of(directive.first, IsDirectiveNameCharacter)) {
//             out->parsing_errors.emplace_back(base::StringPrintf(
//                 "The Content-Security-Policy directive name '%s' contains one or "
//                 "more invalid characters. Only ASCII alphanumeric characters or "
//                 "dashes '-' are allowed in directive names.",
//                 std::string(directive.first).c_str()));
//             continue;
//         }
// 
//         CSPDirectiveName directive_name = ToCSPDirectiveName(std::string(directive.first));
// 
//         if (directive_name == CSPDirectiveName::Unknown) {
//             out->parsing_errors.emplace_back(UnrecognizedDirectiveErrorMessage(std::string(directive.first)));
//             continue;
//         }
// 
//         // A directive with this name has already been parsed. Skip further
//         // directives per
//         // https://www.w3.org/TR/CSP3/#parse-serialized-policy.
//         if (out->raw_directives.count(directive_name)) {
//             out->parsing_errors.emplace_back(base::StringPrintf(
//                 "Ignoring duplicate Content-Security-Policy directive '%s'.",
//                 std::string(directive.first).c_str()));
//             continue;
//         }
//         out->raw_directives[directive_name] = std::string(directive.second);
// 
//         if (!base::ranges::all_of(directive.second, IsDirectiveValueCharacter)) {
//             out->parsing_errors.emplace_back(base::StringPrintf(
//                 "The value for the Content-Security-Policy directive '%s' contains "
//                 "one or more invalid characters. In a source expression, "
//                 "non-whitespace characters outside ASCII "
//                 "0x21-0x7E must be Punycode-encoded, as described in RFC 3492 "
//                 "(https://tools.ietf.org/html/rfc3492), if part of the hostname and "
//                 "percent-encoded, as described in RFC 3986, section 2.1 "
//                 "(http://tools.ietf.org/html/rfc3986#section-2.1), if part of the "
//                 "path.",
//                 std::string(directive.first).c_str()));
//             continue;
//         }
// 
//         if (type == mojom::ContentSecurityPolicyType::kReport && !SupportedInReportOnly(directive_name)) {
//             out->parsing_errors.emplace_back(
//                 base::StringPrintf("The Content Security Policy directive '%s' is "
//                     "ignored when delivered in a report-only policy.",
//                     std::string(directive.first).c_str()));
//             continue;
//         }
// 
//         if (source == mojom::ContentSecurityPolicySource::kMeta && !SupportedInMeta(directive_name)) {
//             out->parsing_errors.emplace_back(
//                 base::StringPrintf("The Content Security Policy directive '%s' is "
//                     "ignored when delivered via a <meta> element.",
//                     std::string(directive.first).c_str()));
//             continue;
//         }
// 
//         switch (directive_name) {
//         case CSPDirectiveName::BaseURI:
//         case CSPDirectiveName::ChildSrc:
//         case CSPDirectiveName::ConnectSrc:
//         case CSPDirectiveName::DefaultSrc:
//         case CSPDirectiveName::FencedFrameSrc:
//         case CSPDirectiveName::FontSrc:
//         case CSPDirectiveName::FormAction:
//         case CSPDirectiveName::FrameAncestors:
//         case CSPDirectiveName::FrameSrc:
//         case CSPDirectiveName::ImgSrc:
//         case CSPDirectiveName::ManifestSrc:
//         case CSPDirectiveName::MediaSrc:
//         case CSPDirectiveName::NavigateTo:
//         case CSPDirectiveName::ObjectSrc:
//         case CSPDirectiveName::PrefetchSrc:
//         case CSPDirectiveName::ScriptSrc:
//         case CSPDirectiveName::ScriptSrcAttr:
//         case CSPDirectiveName::ScriptSrcElem:
//         case CSPDirectiveName::StyleSrc:
//         case CSPDirectiveName::StyleSrcAttr:
//         case CSPDirectiveName::StyleSrcElem:
//         case CSPDirectiveName::WorkerSrc:
//             out->directives[directive_name] = ParseSourceList(directive_name, directive.second, out->parsing_errors);
//             break;
//         case CSPDirectiveName::Sandbox:
//             // Note: Outside of CSP embedded enforcement,
//             // |ParseSandboxPolicy(...).error_message| isn't displayed to the user.
//             // Blink's CSP parser is already in charge of it.
//         {
//             auto sandbox = ParseWebSandboxPolicy(directive.second, mojom::WebSandboxFlags::kNone);
//             out->sandbox = sandbox.flags;
//             if (!sandbox.error_message.empty())
//                 out->parsing_errors.emplace_back("Error while parsing the 'sandbox' Content Security Policy directive: " +
//                     sandbox.error_message);
//         }
//         break;
//         case CSPDirectiveName::UpgradeInsecureRequests:
//             out->upgrade_insecure_requests = true;
//             WarnIfDirectiveValueNotEmpty(directive, out->parsing_errors);
//             break;
//         case CSPDirectiveName::TreatAsPublicAddress:
//             out->treat_as_public_address = true;
//             WarnIfDirectiveValueNotEmpty(directive, out->parsing_errors);
//             break;
//         case CSPDirectiveName::RequireTrustedTypesFor:
//             out->require_trusted_types_for = ParseRequireTrustedTypesFor(directive.second, out->parsing_errors);
//             break;
// 
//         case CSPDirectiveName::TrustedTypes:
//             out->trusted_types = ParseTrustedTypes(directive.second, out->parsing_errors);
//             break;
// 
//         case CSPDirectiveName::BlockAllMixedContent:
//             out->block_all_mixed_content = true;
//             WarnIfDirectiveValueNotEmpty(directive, out->parsing_errors);
//             break;
// 
//         case CSPDirectiveName::ReportTo:
//             out->use_reporting_api = true;
//             out->report_endpoints.clear();
//             ParseReportDirective(base_url, directive.second, out->use_reporting_api, &(out->report_endpoints), out->parsing_errors);
//             break;
//         case CSPDirectiveName::ReportURI:
//             if (!out->use_reporting_api)
//                 ParseReportDirective(base_url, directive.second, out->use_reporting_api, &(out->report_endpoints), out->parsing_errors);
//             break;
//         case CSPDirectiveName::Unknown:
//             break;
//         }
//     }
// }
// 
// std::vector<mojo::StructPtr<network::mojom::ContentSecurityPolicy>>
// ParseContentSecurityPolicies(base::StringPiece header_value, network::mojom::ContentSecurityPolicyType type,
//     network::mojom::ContentSecurityPolicySource source, const GURL& base_url)
// {
// //     if (!header_value.empty())
// //         *(int*)1 = 1;
// //     return std::vector<mojo::StructPtr<network::mojom::ContentSecurityPolicy>>();
//     std::vector<mojom::ContentSecurityPolicyPtr> out;
// 
//     // RFC7230, section 3.2.2 specifies that headers appearing multiple times can
//     // be combined with a comma. Walk the header string, and parse each comma
//     // separated chunk as a separate header.
//     for (const auto& header : base::SplitStringPiece(header_value, ",", base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY)) {
//         auto policy = mojom::ContentSecurityPolicy::New();
//         AddContentSecurityPolicyFromHeader(header, type, source, base_url, policy);
// 
//         out.push_back(std::move(policy));
//     }
// 
//     return out;
// }
//----

namespace mojom {

// When adding a new conversion, define a new `ConvertToBlink` overload to map
// the non-Blink type (passing by value for primitive types or passing by const
// reference otherwise). The generic converters for container types relies on
// the presence of `ConvertToBlink` overloads to determine the correct return
// type.

// ===== Identity converters =====
// Converts where the input type and output type are identical(-ish).
uint8_t ConvertToBlink(uint8_t in)
{
    return in;
}

// Note: for identity enum conversions, there should be `static_assert`s that
// the input enumerator and the output enumerator define matching values.
blink::CSPDirectiveName ConvertToBlink(CSPDirectiveName name)
{
    return static_cast<blink::CSPDirectiveName>(name);
}

// `in` is a Mojo enum type, which is type aliased to the same underlying type
// by both the non-Blink Mojo variant and the Blink Mojo variant.
blink::WebClientHintsType ConvertToBlink(WebClientHintsType in)
{
    return in;
}

blink::LoadingMode ConvertToBlink(LoadingMode in)
{
    return static_cast<blink::LoadingMode>(in);
}

// ===== Converters for other basic Blink types =====
String ConvertToBlink(const std::string& in)
{
    return String::FromUTF8(in);
}

String ConvertToBlink(const absl::optional<std::string>& in)
{
    return in ? String::FromUTF8(*in) : String();
}

::blink::KURL ConvertToBlink(const GURL& in)
{
    return ::blink::KURL(in);
}

scoped_refptr<const ::blink::SecurityOrigin> ConvertToBlink(const url::Origin& in)
{
    return ::blink::SecurityOrigin::CreateFromUrlOrigin(in);
}

// ====== Generic container converters =====
template <typename InElement, typename OutElement = decltype(ConvertToBlink(std::declval<InElement>()))>
Vector<OutElement> ConvertToBlink(const std::vector<InElement>& in)
{
    Vector<OutElement> out;
    out.reserve(base::checked_cast<wtf_size_t>(in.size()));
    for (const auto& element : in) {
        out.push_back(ConvertToBlink(element));
    }
    return out;
}

template <typename InKey, typename InValue, typename OutKey = decltype(ConvertToBlink(std::declval<InKey>())),
    typename OutValue = decltype(ConvertToBlink(std::declval<InValue>()))>
HashMap<OutKey, OutValue> ConvertToBlink(const base::flat_map<InKey, InValue>& in)
{
    HashMap<OutKey, OutValue> out;
    for (const auto& element : in) {
        out.insert(ConvertToBlink(element.first), ConvertToBlink(element.second));
    }
    return out;
}

// ===== Converters from non-Blink to Blink variant of Mojo structs =====
blink::CSPSourcePtr ConvertToBlink(const CSPSourcePtr& in)
{
    DCHECK(in);
    return blink::CSPSource::New(
        ConvertToBlink(in->scheme), ConvertToBlink(in->host), in->port, ConvertToBlink(in->path), in->is_host_wildcard, in->is_port_wildcard);
}

blink::CSPHashSourcePtr ConvertToBlink(const CSPHashSourcePtr& in)
{
    DCHECK(in);
    Vector<uint8_t> hash_value = ConvertToBlink(in->value);

    return blink::CSPHashSource::New(in->algorithm, std::move(hash_value));
}

blink::CSPSourceListPtr ConvertToBlink(const CSPSourceListPtr& source_list)
{
    DCHECK(source_list);

    Vector<blink::CSPSourcePtr> sources = ConvertToBlink(source_list->sources);
    Vector<String> nonces = ConvertToBlink(source_list->nonces);
    Vector<blink::CSPHashSourcePtr> hashes = ConvertToBlink(source_list->hashes);

    return blink::CSPSourceList::New(std::move(sources), std::move(nonces), std::move(hashes), source_list->allow_self, source_list->allow_star,
        source_list->allow_response_redirects, source_list->allow_inline, source_list->allow_eval, source_list->allow_wasm_eval,
        source_list->allow_wasm_unsafe_eval, source_list->allow_dynamic, source_list->allow_unsafe_hashes, source_list->report_sample);
}

blink::ContentSecurityPolicyHeaderPtr ConvertToBlink(const ContentSecurityPolicyHeaderPtr& in)
{
    DCHECK(in);
    return blink::ContentSecurityPolicyHeader::New(ConvertToBlink(in->header_value), in->type, in->source);
}

blink::CSPTrustedTypesPtr ConvertToBlink(const CSPTrustedTypesPtr& in)
{
    if (!in)
        return nullptr;
    return blink::CSPTrustedTypes::New(ConvertToBlink(in->list), in->allow_any, in->allow_duplicates);
}

blink::ContentSecurityPolicyPtr ConvertToBlink(const ContentSecurityPolicyPtr& in)
{
    DCHECK(in);
    return blink::ContentSecurityPolicy::New(ConvertToBlink(in->self_origin), ConvertToBlink(in->raw_directives), ConvertToBlink(in->directives),
        in->upgrade_insecure_requests, in->treat_as_public_address, in->block_all_mixed_content, in->sandbox, ConvertToBlink(in->header), in->use_reporting_api,
        ConvertToBlink(in->report_endpoints), in->require_trusted_types_for, ConvertToBlink(in->trusted_types), ConvertToBlink(in->parsing_errors));
}

blink::AllowCSPFromHeaderValuePtr ConvertToBlink(const AllowCSPFromHeaderValuePtr& allow_csp_from)
{
    if (!allow_csp_from)
        return nullptr;
    switch (allow_csp_from->which()) {
    case AllowCSPFromHeaderValue::Tag::kAllowStar:
        return blink::AllowCSPFromHeaderValue::NewAllowStar(allow_csp_from->get_allow_star());
    case AllowCSPFromHeaderValue::Tag::kOrigin:
        return blink::AllowCSPFromHeaderValue::NewOrigin(ConvertToBlink(allow_csp_from->get_origin()));
    case AllowCSPFromHeaderValue::Tag::kErrorMessage:
        return blink::AllowCSPFromHeaderValue::NewErrorMessage(ConvertToBlink(allow_csp_from->get_error_message()));
    }
    return nullptr;
}

blink::LinkHeaderPtr ConvertToBlink(const LinkHeaderPtr& in)
{
    DCHECK(in);
    return blink::LinkHeader::New(ConvertToBlink(in->href),
        // TODO(dcheng): Make these use ConvertToBlink
        static_cast<blink::LinkRelAttribute>(in->rel), static_cast<blink::LinkAsAttribute>(in->as), static_cast<blink::CrossOriginAttribute>(in->cross_origin),
        ConvertToBlink(in->mime_type));
}

blink::TimingAllowOriginPtr ConvertToBlink(const TimingAllowOriginPtr& in)
{
    if (!in)
        return nullptr;

    switch (in->which()) {
    case TimingAllowOrigin::Tag::kSerializedOrigins:
        return blink::TimingAllowOrigin::NewSerializedOrigins(ConvertToBlink(in->get_serialized_origins()));
    case TimingAllowOrigin::Tag::kAll:
        return blink::TimingAllowOrigin::NewAll(/*ignored=*/0);
    }
    return nullptr;
}

blink::VariantsHeaderPtr ConvertToBlink(const VariantsHeaderPtr& in)
{
    DCHECK(in);
    return blink::VariantsHeader::New(ConvertToBlink(in->name), ConvertToBlink(in->available_values));
}

blink::ParsedHeadersPtr ConvertToBlink(const ParsedHeadersPtr& in)
{
    DCHECK(in);
    return blink::ParsedHeaders::New(ConvertToBlink(in->content_security_policy), ConvertToBlink(in->allow_csp_from), in->cross_origin_embedder_policy,
        in->cross_origin_opener_policy, in->origin_agent_cluster,
        in->accept_ch.has_value() ? absl::make_optional(ConvertToBlink(in->accept_ch.value())) : absl::nullopt,
        in->critical_ch.has_value() ? absl::make_optional(ConvertToBlink(in->critical_ch.value())) : absl::nullopt, in->xfo, ConvertToBlink(in->link_headers),
        ConvertToBlink(in->timing_allow_origin), ConvertToBlink(in->supports_loading_mode),
        in->reporting_endpoints.has_value() ? absl::make_optional(ConvertToBlink(in->reporting_endpoints.value())) : absl::nullopt,
        in->variants_headers.has_value() ? absl::make_optional(ConvertToBlink(in->variants_headers.value())) : absl::nullopt,
        in->content_language.has_value() ? absl::make_optional(ConvertToBlink(in->content_language.value())) : absl::nullopt);
}

} // namespace mojom
} // namespace network

namespace blink {

namespace {

const Vector<AtomicString>& ReplaceHeaders()
{
    // The list of response headers that we do not copy from the original
    // response when generating a ResourceResponse for a MIME payload.
    // Note: this is called only on the main thread.
    DEFINE_STATIC_LOCAL(Vector<AtomicString>, headers, ({ "content-type", "content-length", "content-disposition", "content-range", "range", "set-cookie" }));
    return headers;
}

bool IsWhitespace(UChar chr)
{
    return (chr == ' ') || (chr == '\t');
}

// true if there is more to parse, after incrementing pos past whitespace.
// Note: Might return pos == str.length()
// if |matcher| is nullptr, isWhitespace() is used.
inline bool SkipWhiteSpace(const String& str, unsigned& pos, WTF::CharacterMatchFunctionPtr matcher = nullptr)
{
    unsigned len = str.length();

    if (matcher) {
        while (pos < len && matcher(str[pos]))
            ++pos;
    } else {
        while (pos < len && IsWhitespace(str[pos]))
            ++pos;
    }

    return pos < len;
}

template <typename CharType> inline bool IsASCIILowerAlphaOrDigit(CharType c)
{
    return IsASCIILower(c) || IsASCIIDigit(c);
}

template <typename CharType> inline bool IsASCIILowerAlphaOrDigitOrHyphen(CharType c)
{
    return IsASCIILowerAlphaOrDigit(c) || c == '-';
}

// Parse a number with ignoring trailing [0-9.].
// Returns false if the source contains invalid characters.
bool ParseRefreshTime(const String& source, base::TimeDelta& delay)
{
    int full_stop_count = 0;
    unsigned number_end = source.length();
    for (unsigned i = 0; i < source.length(); ++i) {
        UChar ch = source[i];
        if (ch == kFullstopCharacter) {
            // TODO(tkent): According to the HTML specification, we should support
            // only integers. However we support fractional numbers.
            if (++full_stop_count == 2)
                number_end = i;
        } else if (!IsASCIIDigit(ch)) {
            return false;
        }
    }
    bool ok;
    double time = source.Left(number_end).ToDouble(&ok);
    if (!ok)
        return false;
    delay = base::Seconds(time);
    return true;
}

} // namespace

bool IsValidHTTPHeaderValue(const String& name)
{
    // FIXME: This should really match name against
    // field-value in section 4.2 of RFC 2616.

    return name.ContainsOnlyLatin1OrEmpty() && !name.Contains('\r') && !name.Contains('\n') && !name.Contains('\0');
}

// See RFC 7230, Section 3.2.6.
bool IsValidHTTPToken(const String& characters)
{
    if (characters.empty())
        return false;
    for (unsigned i = 0; i < characters.length(); ++i) {
        UChar c = characters[i];
        if (c > 0x7F || !net::HttpUtil::IsTokenChar(c))
            return false;
    }
    return true;
}

bool IsContentDispositionAttachment(const String& content_disposition)
{
    return net::HttpContentDisposition(content_disposition.Utf8(), std::string()).is_attachment();
}

// https://html.spec.whatwg.org/C/#attr-meta-http-equiv-refresh
bool ParseHTTPRefresh(const String& refresh, WTF::CharacterMatchFunctionPtr matcher, base::TimeDelta& delay, String& url)
{
    unsigned len = refresh.length();
    unsigned pos = 0;
    matcher = matcher ? matcher : IsWhitespace;

    if (!SkipWhiteSpace(refresh, pos, matcher))
        return false;

    while (pos != len && refresh[pos] != ',' && refresh[pos] != ';' && !matcher(refresh[pos]))
        ++pos;

    if (pos == len) { // no URL
        url = String();
        return ParseRefreshTime(refresh.StripWhiteSpace(), delay);
    } else {
        if (!ParseRefreshTime(refresh.Left(pos).StripWhiteSpace(), delay))
            return false;

        SkipWhiteSpace(refresh, pos, matcher);
        if (pos < len && (refresh[pos] == ',' || refresh[pos] == ';'))
            ++pos;
        SkipWhiteSpace(refresh, pos, matcher);
        unsigned url_start_pos = pos;
        if (refresh.FindIgnoringASCIICase("url", url_start_pos) == url_start_pos) {
            url_start_pos += 3;
            SkipWhiteSpace(refresh, url_start_pos, matcher);
            if (refresh[url_start_pos] == '=') {
                ++url_start_pos;
                SkipWhiteSpace(refresh, url_start_pos, matcher);
            } else {
                url_start_pos = pos; // e.g. "Refresh: 0; url.html"
            }
        }

        unsigned url_end_pos = len;

        if (refresh[url_start_pos] == '"' || refresh[url_start_pos] == '\'') {
            UChar quotation_mark = refresh[url_start_pos];
            url_start_pos++;
            while (url_end_pos > url_start_pos) {
                url_end_pos--;
                if (refresh[url_end_pos] == quotation_mark)
                    break;
            }

            // https://bugs.webkit.org/show_bug.cgi?id=27868
            // Sometimes there is no closing quote for the end of the URL even though
            // there was an opening quote.  If we looped over the entire alleged URL
            // string back to the opening quote, just go ahead and use everything
            // after the opening quote instead.
            if (url_end_pos == url_start_pos)
                url_end_pos = len;
        }

        url = refresh.Substring(url_start_pos, url_end_pos - url_start_pos).StripWhiteSpace();
        return true;
    }
}

absl::optional<base::Time> ParseDate(const String& value)
{
    return ParseDateFromNullTerminatedCharacters(value.Utf8().c_str());
}

AtomicString ExtractMIMETypeFromMediaType(const AtomicString& media_type)
{
    unsigned length = media_type.length();

    unsigned pos = 0;

    while (pos < length) {
        UChar c = media_type[pos];
        if (c != '\t' && c != ' ')
            break;
        ++pos;
    }

    if (pos == length)
        return media_type;

    unsigned type_start = pos;

    unsigned type_end = pos;
    while (pos < length) {
        UChar c = media_type[pos];

        // While RFC 2616 does not allow it, other browsers allow multiple values in
        // the HTTP media type header field, Content-Type. In such cases, the media
        // type string passed here may contain the multiple values separated by
        // commas. For now, this code ignores text after the first comma, which
        // prevents it from simply failing to parse such types altogether.  Later
        // for better compatibility we could consider using the first or last valid
        // MIME type instead.
        // See https://bugs.webkit.org/show_bug.cgi?id=25352 for more discussion.
        if (c == ',' || c == ';')
            break;

        if (c != '\t' && c != ' ')
            type_end = pos + 1;

        ++pos;
    }

    return AtomicString(media_type.GetString().Substring(type_start, type_end - type_start));
}

ContentTypeOptionsDisposition ParseContentTypeOptionsHeader(const String& value)
{
    if (value.empty())
        return kContentTypeOptionsNone;

    Vector<String> results;
    value.Split(",", results);
    if (results.size() && results[0].StripWhiteSpace().LowerASCII() == "nosniff")
        return kContentTypeOptionsNosniff;
    return kContentTypeOptionsNone;
}

static bool IsCacheHeaderSeparator(UChar c)
{
    // See RFC 2616, Section 2.2
    switch (c) {
    case '(':
    case ')':
    case '<':
    case '>':
    case '@':
    case ',':
    case ';':
    case ':':
    case '\\':
    case '"':
    case '/':
    case '[':
    case ']':
    case '?':
    case '=':
    case '{':
    case '}':
    case ' ':
    case '\t':
        return true;
    default:
        return false;
    }
}

static bool IsControlCharacter(UChar c)
{
    return c < ' ' || c == 127;
}

static inline String TrimToNextSeparator(const String& str)
{
    return str.Substring(0, str.Find(IsCacheHeaderSeparator));
}

static void ParseCacheHeader(const String& header, Vector<std::pair<String, String>>& result)
{
    const String safe_header = header.RemoveCharacters(IsControlCharacter);
    wtf_size_t max = safe_header.length();
    for (wtf_size_t pos = 0; pos < max; /* pos incremented in loop */) {
        wtf_size_t next_comma_position = safe_header.find(',', pos);
        wtf_size_t next_equal_sign_position = safe_header.find('=', pos);
        if (next_equal_sign_position != kNotFound && (next_equal_sign_position < next_comma_position || next_comma_position == kNotFound)) {
            // Get directive name, parse right hand side of equal sign, then add to
            // map
            String directive = TrimToNextSeparator(safe_header.Substring(pos, next_equal_sign_position - pos).StripWhiteSpace());
            pos += next_equal_sign_position - pos + 1;

            String value = safe_header.Substring(pos, max - pos).StripWhiteSpace();
            if (value[0] == '"') {
                // The value is a quoted string
                wtf_size_t next_double_quote_position = value.find('"', 1);
                if (next_double_quote_position != kNotFound) {
                    // Store the value as a quoted string without quotes
                    result.push_back(std::pair<String, String>(directive, value.Substring(1, next_double_quote_position - 1).StripWhiteSpace()));
                    pos += (safe_header.find('"', pos) - pos) + next_double_quote_position + 1;
                    // Move past next comma, if there is one
                    wtf_size_t next_comma_position2 = safe_header.find(',', pos);
                    if (next_comma_position2 != kNotFound)
                        pos += next_comma_position2 - pos + 1;
                    else
                        return; // Parse error if there is anything left with no comma
                } else {
                    // Parse error; just use the rest as the value
                    result.push_back(std::pair<String, String>(directive, TrimToNextSeparator(value.Substring(1, value.length() - 1).StripWhiteSpace())));
                    return;
                }
            } else {
                // The value is a token until the next comma
                wtf_size_t next_comma_position2 = value.find(',');
                if (next_comma_position2 != kNotFound) {
                    // The value is delimited by the next comma
                    result.push_back(std::pair<String, String>(directive, TrimToNextSeparator(value.Substring(0, next_comma_position2).StripWhiteSpace())));
                    pos += (safe_header.find(',', pos) - pos) + 1;
                } else {
                    // The rest is the value; no change to value needed
                    result.push_back(std::pair<String, String>(directive, TrimToNextSeparator(value)));
                    return;
                }
            }
        } else if (next_comma_position != kNotFound && (next_comma_position < next_equal_sign_position || next_equal_sign_position == kNotFound)) {
            // Add directive to map with empty string as value
            result.push_back(std::pair<String, String>(TrimToNextSeparator(safe_header.Substring(pos, next_comma_position - pos).StripWhiteSpace()), ""));
            pos += next_comma_position - pos + 1;
        } else {
            // Add last directive to map with empty string as value
            result.push_back(std::pair<String, String>(TrimToNextSeparator(safe_header.Substring(pos, max - pos).StripWhiteSpace()), ""));
            return;
        }
    }
}

CacheControlHeader ParseCacheControlDirectives(const AtomicString& cache_control_value, const AtomicString& pragma_value)
{
    CacheControlHeader cache_control_header;
    cache_control_header.parsed = true;
    cache_control_header.max_age = absl::nullopt;
    cache_control_header.stale_while_revalidate = absl::nullopt;

    static const char kNoCacheDirective[] = "no-cache";
    static const char kNoStoreDirective[] = "no-store";
    static const char kMustRevalidateDirective[] = "must-revalidate";
    static const char kMaxAgeDirective[] = "max-age";
    static const char kStaleWhileRevalidateDirective[] = "stale-while-revalidate";

    if (!cache_control_value.empty()) {
        Vector<std::pair<String, String>> directives;
        ParseCacheHeader(cache_control_value, directives);

        wtf_size_t directives_size = directives.size();
        for (wtf_size_t i = 0; i < directives_size; ++i) {
            // RFC2616 14.9.1: A no-cache directive with a value is only meaningful
            // for proxy caches.  It should be ignored by a browser level cache.
            if (EqualIgnoringASCIICase(directives[i].first, kNoCacheDirective) && directives[i].second.empty()) {
                cache_control_header.contains_no_cache = true;
            } else if (EqualIgnoringASCIICase(directives[i].first, kNoStoreDirective)) {
                cache_control_header.contains_no_store = true;
            } else if (EqualIgnoringASCIICase(directives[i].first, kMustRevalidateDirective)) {
                cache_control_header.contains_must_revalidate = true;
            } else if (EqualIgnoringASCIICase(directives[i].first, kMaxAgeDirective)) {
                if (cache_control_header.max_age) {
                    // First max-age directive wins if there are multiple ones.
                    continue;
                }
                bool ok;
                double max_age = directives[i].second.ToDouble(&ok);
                if (ok)
                    cache_control_header.max_age = base::Seconds(max_age);
            } else if (EqualIgnoringASCIICase(directives[i].first, kStaleWhileRevalidateDirective)) {
                if (cache_control_header.stale_while_revalidate) {
                    // First stale-while-revalidate directive wins if there are multiple
                    // ones.
                    continue;
                }
                bool ok;
                double stale_while_revalidate = directives[i].second.ToDouble(&ok);
                if (ok) {
                    cache_control_header.stale_while_revalidate = base::Seconds(stale_while_revalidate);
                }
            }
        }
    }

    if (!cache_control_header.contains_no_cache) {
        // Handle Pragma: no-cache
        // This is deprecated and equivalent to Cache-control: no-cache
        // Don't bother tokenizing the value, it is not important
        cache_control_header.contains_no_cache = pragma_value.LowerASCII().Contains(kNoCacheDirective);
    }
    return cache_control_header;
}

void ParseCommaDelimitedHeader(const String& header_value, CommaDelimitedHeaderSet& header_set)
{
    Vector<String> results;
    header_value.Split(",", results);
    for (auto& value : results)
        header_set.insert(value.StripWhiteSpace(IsWhitespace));
}

bool ParseMultipartHeadersFromBody(const char* bytes, wtf_size_t size, ResourceResponse* response, wtf_size_t* end)
{
    DCHECK(IsMainThread());

    size_t headers_end_pos = net::HttpUtil::LocateEndOfAdditionalHeaders(bytes, size, 0);

    if (headers_end_pos == std::string::npos)
        return false;

    *end = static_cast<wtf_size_t>(headers_end_pos);

    // Eat headers and prepend a status line as is required by
    // HttpResponseHeaders.
    std::string headers("HTTP/1.1 200 OK\r\n");
    headers.append(bytes, headers_end_pos);

    auto response_headers = base::MakeRefCounted<net::HttpResponseHeaders>(net::HttpUtil::AssembleRawHeaders(headers));

    std::string mime_type, charset;
    response_headers->GetMimeTypeAndCharset(&mime_type, &charset);
    response->SetMimeType(WebString::FromUTF8(mime_type));
    response->SetTextEncodingName(WebString::FromUTF8(charset));

    // Copy headers listed in replaceHeaders to the response.
    for (const AtomicString& header : ReplaceHeaders()) {
        std::string value;
        StringUTF8Adaptor adaptor(header);
        base::StringPiece header_string_piece(adaptor.AsStringPiece());
        size_t iterator = 0;

        response->ClearHttpHeaderField(header);
        Vector<AtomicString> values;
        while (response_headers->EnumerateHeader(&iterator, header_string_piece, &value)) {
            const AtomicString atomic_value = WebString::FromLatin1(value);
            values.push_back(atomic_value);
        }
        response->AddHttpHeaderFieldWithMultipleValues(header, values);
    }
    return true;
}

bool ParseMultipartFormHeadersFromBody(const char* bytes, wtf_size_t size, HTTPHeaderMap* header_fields, wtf_size_t* end)
{
    DCHECK_EQ(0u, header_fields->size());

    size_t headers_end_pos = net::HttpUtil::LocateEndOfAdditionalHeaders(bytes, size, 0);

    if (headers_end_pos == std::string::npos)
        return false;

    *end = static_cast<wtf_size_t>(headers_end_pos);

    // Eat headers and prepend a status line as is required by
    // HttpResponseHeaders.
    std::string headers("HTTP/1.1 200 OK\r\n");
    headers.append(bytes, headers_end_pos);

    auto responseHeaders = base::MakeRefCounted<net::HttpResponseHeaders>(net::HttpUtil::AssembleRawHeaders(headers));

    // Copy selected header fields.
    const AtomicString* const headerNamePointers[] = { &http_names::kContentDisposition, &http_names::kContentType };
    for (const AtomicString* headerNamePointer : headerNamePointers) {
        StringUTF8Adaptor adaptor(*headerNamePointer);
        size_t iterator = 0;
        base::StringPiece headerNameStringPiece = adaptor.AsStringPiece();
        std::string value;
        while (responseHeaders->EnumerateHeader(&iterator, headerNameStringPiece, &value)) {
            header_fields->Add(*headerNamePointer, WebString::FromUTF8(value));
        }
    }

    return true;
}

bool ParseContentRangeHeaderFor206(const String& content_range, int64_t* first_byte_position, int64_t* last_byte_position, int64_t* instance_length)
{
    return net::HttpUtil::ParseContentRangeHeaderFor206(
        StringUTF8Adaptor(content_range).AsStringPiece(), first_byte_position, last_byte_position, instance_length);
}

std::unique_ptr<ServerTimingHeaderVector> ParseServerTimingHeader(const String& headerValue)
{
    std::unique_ptr<ServerTimingHeaderVector> headers = std::make_unique<ServerTimingHeaderVector>();

    if (!headerValue.IsNull()) {
        DCHECK(headerValue.Is8Bit());

        HeaderFieldTokenizer tokenizer(headerValue);
        while (!tokenizer.IsConsumed()) {
            StringView name;
            if (!tokenizer.ConsumeToken(ParsedContentType::Mode::kNormal, name)) {
                break;
            }

            ServerTimingHeader header(name.ToString());

            tokenizer.ConsumeBeforeAnyCharMatch({ ',', ';' });

            while (tokenizer.Consume(';')) {
                StringView parameter_name;
                if (!tokenizer.ConsumeToken(ParsedContentType::Mode::kNormal, parameter_name)) {
                    break;
                }

                String value = "";
                if (tokenizer.Consume('=')) {
                    tokenizer.ConsumeTokenOrQuotedString(ParsedContentType::Mode::kNormal, value);
                    tokenizer.ConsumeBeforeAnyCharMatch({ ',', ';' });
                }
                header.SetParameter(parameter_name, value);
            }

            headers->push_back(std::make_unique<ServerTimingHeader>(header));

            if (!tokenizer.Consume(',')) {
                break;
            }
        }
    }
    return headers;
}

// This function is simply calling network::ParseHeaders and convert from/to
// blink types. It is used for navigation requests served by a ServiceWorker. It
// is tested by FetchResponseDataTest.ContentSecurityPolicy.
network::mojom::blink::ParsedHeadersPtr ParseHeaders(const String& raw_headers, const KURL& url)
{
    *(int*)1 = 1;
    return nullptr;
    //     auto headers = base::MakeRefCounted<net::HttpResponseHeaders>(net::HttpUtil::AssembleRawHeaders(raw_headers.Latin1()));
    //     return network::mojom::ConvertToBlink(network::PopulateParsedHeaders(headers.get(), GURL(url)));
}

// This function is simply calling network::ParseContentSecurityPolicies and
// converting from/to blink types.
Vector<network::mojom::blink::ContentSecurityPolicyPtr> ParseContentSecurityPolicies(const String& raw_policies,
    network::mojom::blink::ContentSecurityPolicyType type, network::mojom::blink::ContentSecurityPolicySource source, const KURL& base_url)
{
    return network::mojom::ConvertToBlink(network::ParseContentSecurityPolicies(raw_policies.Utf8(), type, source, GURL(base_url)));
}

// This function is simply calling network::ParseContentSecurityPolicies and
// converting from/to blink types.
Vector<network::mojom::blink::ContentSecurityPolicyPtr> ParseContentSecurityPolicies(const String& raw_policies,
    network::mojom::blink::ContentSecurityPolicyType type, network::mojom::blink::ContentSecurityPolicySource source, const SecurityOrigin& self_origin)
{
    const SecurityOrigin* precursor_origin = self_origin.GetOriginOrPrecursorOriginIfOpaque();
    KURL base_url;
    base_url.SetProtocol(precursor_origin->Protocol());
    base_url.SetHost(precursor_origin->Host());
    base_url.SetPort(precursor_origin->Port());
    return ParseContentSecurityPolicies(raw_policies, type, source, base_url);
}

Vector<network::mojom::blink::ContentSecurityPolicyPtr> ParseContentSecurityPolicyHeaders(const ContentSecurityPolicyResponseHeaders& headers)
{
    Vector<network::mojom::blink::ContentSecurityPolicyPtr> parsed_csps = ParseContentSecurityPolicies(headers.ContentSecurityPolicy(),
        network::mojom::blink::ContentSecurityPolicyType::kEnforce, network::mojom::blink::ContentSecurityPolicySource::kHTTP, headers.ResponseUrl());
    Vector<network::mojom::blink::ContentSecurityPolicyPtr> report_only_csps = ParseContentSecurityPolicies(headers.ContentSecurityPolicyReportOnly(),
        network::mojom::blink::ContentSecurityPolicyType::kReport, network::mojom::blink::ContentSecurityPolicySource::kHTTP, headers.ResponseUrl());
    parsed_csps.AppendRange(std::make_move_iterator(report_only_csps.begin()), std::make_move_iterator(report_only_csps.end()));
    return parsed_csps;
}

network::mojom::blink::TimingAllowOriginPtr ParseTimingAllowOrigin(const String& header_value)
{
    //return network::mojom::ConvertToBlink(network::ParseTimingAllowOrigin(header_value.Latin1()));
    *(int*)1 = 1;
    return nullptr;
}

} // namespace blink
