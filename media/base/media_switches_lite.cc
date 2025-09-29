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


#include "media/base/media_switches.h"

#include "base/command_line.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
// #include "components/system_media_controls/linux/buildflags/buildflags.h"
#include "media/media_buildflags.h"

#if BUILDFLAG(IS_LINUX)
#include "base/cpu.h"
#endif

namespace media {

//BASE_FEATURE(kRevokeMediaSourceObjectURLOnAttach, "RevokeMediaSourceObjectURLOnAttach", base::FEATURE_ENABLED_BY_DEFAULT);

// Use R16 texture for 9-16 bit channel instead of half-float conversion by CPU.
//BASE_FEATURE(kUseR16Texture, "use-r16-texture", base::FEATURE_DISABLED_BY_DEFAULT);

}