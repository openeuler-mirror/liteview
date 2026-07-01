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


#ifndef download_DownloadUtil_h
#define download_DownloadUtil_h

#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "content/common/StringUtil.h"
#include "content/common/UrlUtil.h"
#include <string>
#include <string_view>
#include <optional>
#include <cctype>
#include <vector>
#include <algorithm>

namespace download {

static unsigned char fromHex(unsigned char x)
{
    unsigned char y;
    if (x >= 'A' && x <= 'Z')
        y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z')
        y = x - 'a' + 10;
    else if (x >= '0' && x <= '9')
        y = x - '0';
    else
        DebugBreak();
    return y;
}

static std::string urlDecode(const std::string& str)
{
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        if (str[i] == '+')
            strTemp += ' ';
        else if (str[i] == '%') {
            if (i + 2 >= length)
                break;
            unsigned char high = fromHex((unsigned char)str[++i]);
            unsigned char low = fromHex((unsigned char)str[++i]);
            strTemp += high * 16 + low;
        } else
            strTemp += str[i];
    }
    return strTemp;
}

static bool icmp(char a, char b)
{
    return tolower(static_cast<unsigned char>(a)) == tolower(static_cast<unsigned char>(b));
}

static size_t findCaseInsensitive(const std::string& str, const std::string& sub)
{
    if (sub.empty()) return 0;
    if (str.size() < sub.size()) return std::string::npos;

    for (size_t i = 0; i <= str.size() - sub.size(); ++i) {
        bool match = true;
        for (size_t j = 0; j < sub.size(); ++j) {
            if (!icmp(str[i + j], sub[j])) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }
    return std::string::npos;
}

// attachment; filename="11??1.docx"; filename*=UTF-8''11%E6%B5%8B%E8%AF%951.docx
static std::u16string getSaveNameFromContentDisposition2(const std::string& str)
{
    if (0 == str.size())
        return std::u16string();

    if (std::string::npos == str.find("attachment"))
        return std::u16string();

    if (std::string::npos == findCaseInsensitive(str, "name"))
        return std::u16string();

    size_t pos1 = str.find("UTF-8''");
    if (std::string::npos == pos1) {
        pos1 = str.find('=');
        if (std::string::npos == pos1)
            return std::u16string();
        pos1++;
    } else {
        pos1 += 7; // UTF-8''
    }

    size_t pos2 = str.size();
    std::string path = str.substr(pos1, pos2 - pos1);
    if (path.empty())
        return std::u16string();

    if ('"' == path[0])
        path.erase(0, 1);
    if (path.empty())
        return std::u16string();

    //     if ('"' == path[path.size() - 1])
    //         path.erase(path.size() - 1, 1);
    size_t doubleQuotationPos = path.find('"'); // 文件名不允许有双引号
    if (std::string::npos != doubleQuotationPos) {
        path.erase(doubleQuotationPos);
    }

    if (path.empty())
        return std::u16string();

    path = urlDecode(path);
    return content::mulByteToUtf16(path, content::isTextUTF8(path.c_str(), path.size()) ? CP_UTF8 : CP_ACP);
}

std::string parseContentDispositionFilename(const std::string& header)
{
    std::string filenameNormal;
    std::string filenameStar;

    size_t i = 0;
    size_t n = header.length();

    auto skipWhitespace = [&]() {
        while (i < n && std::isspace(static_cast<unsigned char>(header[i]))) ++i;
    };

    while (i < n) {
        skipWhitespace();
        if (i >= n) break;

        // 1. 提取 Key (遇到 '=' 或 ';' 前的内容)
        std::string key;
        while (i < n && header[i] != '=' && header[i] != ';' && !std::isspace(static_cast<unsigned char>(header[i]))) {
            key += static_cast<char>(std::tolower(static_cast<unsigned char>(header[i])));
            ++i;
        }

        skipWhitespace();

        // 2. 提取 Value
        std::string val;
        bool isKV = false;

        if (i < n && header[i] == '=') {
            isKV = true;
            ++i; // 跳过 '='
            skipWhitespace();

            if (i < n && header[i] == '"') {
                // 处理带双引号的值 (Quoted-string)
                ++i; // 跳过左引号
                bool escape = false;
                while (i < n) {
                    if (escape) {
                        val += header[i];
                        escape = false;
                    } else if (header[i] == '\\') {
                        escape = true; // 处理转义字符
                    } else if (header[i] == '"') {
                        ++i; // 跳过右引号
                        break;
                    } else {
                        val += header[i];
                    }
                    ++i;
                }
            } else {
                // 处理无引号的值 (Token)
                while (i < n && header[i] != ';' && !std::isspace(static_cast<unsigned char>(header[i]))) {
                    val += header[i];
                    ++i;
                }
            }
        }

        // 3. 记录 filename 和 filename*
        if (isKV) {
            if (key == "filename*") {
                // 格式为: charset'language'encoded_value
                size_t firstQuote = val.find('\'');
                if (firstQuote != std::string::npos) {
                    size_t secondQuote = val.find('\'', firstQuote + 1);
                    if (secondQuote != std::string::npos) {
                        // 提取第二个单引号之后的部分
                        filenameStar = val.substr(secondQuote + 1);
                    }
                }
            } else if (key == "filename") {
                filenameNormal = val;
            }
        }

        // 4. 移动到下一个分号 ';' 继续解析下一个参数
        while (i < n && header[i] != ';') ++i;
        if (i < n && header[i] == ';') ++i;
    }

    // RFC 规范：如果 filename* 存在，其优先级高于普通的 filename
    return !filenameStar.empty() ? filenameStar : filenameNormal;
}

// "attachment; filename*=utf-8''%E6%B5%8B.txt"
// "attachment; filename=\"%E6%B5%8B.txt\"";
// "attachment; filename*=utf-8''%E6%B5%8B%E8%AF%95.txt"; //基础情况 filename*
// "attachment; filename=\"xxxx.txt\""; // 带双引号的普通 filename
// "attachment; filename*=utf-8'zh-CN'%E6%B5%8B%E8%AF%95.txt"; // 带有 language (zh-CN) 的 filename*
// "attachment; filename=\"fallback.txt\"; filename*=utf-8''%E6%B5%8B%E8%AF%95.txt"; // 同时存在 filename 和 filename* (应优先选择 filename*)
// "attachment; filename=\"edge;case.txt\""; // 边缘情况 - 双引号内部包含分号（破坏简单 split 的情况）
// " inline ; FILEname  =  \"space.txt\" "; // 边缘情况 - 包含空格和大小写混乱
static std::u16string getSaveName(std::string contentDisposition, std::string url)
{
    //std::u16string result = getSaveNameFromContentDisposition(contentDisposition);
    //if (!result.empty())
    //    return result;

    std::u16string result;
    std::string path = parseContentDispositionFilename(contentDisposition);
    if (!path.empty()) {
        path = urlDecode(path);
        return content::mulByteToUtf16(path, content::isTextUTF8(path.c_str(), path.size()) ? CP_UTF8 : CP_ACP);
    }

    result = content::UrlUtil::getSaveNameFromUrl(url);
    String str = blink::DecodeURLEscapeSequences(WTF::String((const UChar*)result.c_str(), result.size()), url::DecodeURLMode::kUTF8);
    result = content::utf8ToUtf16(str.Utf8());

    return result;
}

}

#endif // download_DownloadUtil_h