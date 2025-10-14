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


#include "net/http/structured_headers.h"

namespace net {
namespace structured_headers {

Item::Item() {}
Item::Item(std::string value, Item::ItemType type)
{
    switch (type) {
    case kStringType:
        value_.emplace<kStringType>(std::move(value));
        break;
    case kTokenType:
        value_.emplace<kTokenType>(std::move(value));
        break;
    case kByteSequenceType:
        value_.emplace<kByteSequenceType>(std::move(value));
        break;
    default:
        CHECK(false);
        break;
    }
}
Item::Item(const char* value, Item::ItemType type)
    : Item(std::string(value), type) {}
Item::Item(int64_t value) : value_(value) {}
Item::Item(double value) : value_(value) {}
Item::Item(bool value) : value_(value) {}

bool operator==(const Item& lhs, const Item& rhs)
{
    return lhs.value_ == rhs.value_;
}

ParameterizedItem::ParameterizedItem(const ParameterizedItem&) = default;
ParameterizedItem& ParameterizedItem::operator=(const ParameterizedItem&) =
default;
ParameterizedItem::ParameterizedItem(Item id, Parameters ps)
    : item(std::move(id)), params(std::move(ps)) {}
ParameterizedItem::~ParameterizedItem() = default;

ParameterizedMember::ParameterizedMember() = default;
ParameterizedMember::ParameterizedMember(const ParameterizedMember&) = default;
ParameterizedMember& ParameterizedMember::operator=(
    const ParameterizedMember&) = default;
ParameterizedMember::ParameterizedMember(std::vector<ParameterizedItem> id,
    bool member_is_inner_list,
    Parameters ps)
    : member(std::move(id)),
    member_is_inner_list(member_is_inner_list),
    params(std::move(ps)) {}
ParameterizedMember::ParameterizedMember(std::vector<ParameterizedItem> id,
    Parameters ps)
    : member(std::move(id)),
    member_is_inner_list(true),
    params(std::move(ps)) {}
ParameterizedMember::ParameterizedMember(Item id, Parameters ps)
    : member({ {std::move(id), {}} }),
    member_is_inner_list(false),
    params(std::move(ps)) {}
ParameterizedMember::~ParameterizedMember() = default;

ParameterisedIdentifier::ParameterisedIdentifier(
    const ParameterisedIdentifier&) = default;
ParameterisedIdentifier& ParameterisedIdentifier::operator=(
    const ParameterisedIdentifier&) = default;
ParameterisedIdentifier::ParameterisedIdentifier(Item id, Parameters ps)
    : identifier(std::move(id)), params(std::move(ps)) {}
ParameterisedIdentifier::~ParameterisedIdentifier() = default;

absl::optional<std::string> SerializeList(const List& value) 
{
    StructuredHeaderSerializer s;
    if (s.WriteList(value)) return s.Output();
    return absl::nullopt;
}

absl::optional<std::string> SerializeItem(const Item& value)
{
    StructuredHeaderSerializer s;
    if (s.WriteItem(ParameterizedItem(value, {}))) return s.Output();
    return absl::nullopt;
}

absl::optional<std::string> SerializeItem(const ParameterizedItem& value)
{
    StructuredHeaderSerializer s;
    if (s.WriteItem(value)) return s.Output();
    return absl::nullopt;
}

}
}