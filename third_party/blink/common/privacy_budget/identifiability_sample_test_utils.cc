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

#include "third_party/blink/public/common/privacy_budget/identifiability_sample_test_utils.h"

namespace blink {

bool CountingSettingsProvider::IsActive() const
{
    ++state_->count_of_is_active;
    return state_->response_for_is_active;
}

bool CountingSettingsProvider::IsAnyTypeOrSurfaceBlocked() const
{
    ++state_->count_of_is_any_type_or_surface_blocked;
    return state_->response_for_is_anything_blocked;
}

bool CountingSettingsProvider::IsSurfaceAllowed(IdentifiableSurface surface) const
{
    ++state_->count_of_is_surface_allowed;
    return state_->response_for_is_allowed;
}

bool CountingSettingsProvider::IsTypeAllowed(IdentifiableSurface::Type type) const
{
    ++state_->count_of_is_type_allowed;
    return state_->response_for_is_allowed;
}

bool CountingSettingsProvider::ShouldActivelySample() const
{
    return false;
}

} // namespace blink
