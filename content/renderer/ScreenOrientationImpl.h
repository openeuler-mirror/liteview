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


#ifndef content_renderer_ScreenOrientationImpl_h
#define content_renderer_ScreenOrientationImpl_h

#include "services/device/public/mojom/screen_orientation.mojom-blink.h"
#include "services/device/public/mojom/screen_orientation_lock_types.mojom-shared.h"

namespace content {

class ScreenOrientationImpl : public ::device::mojom::blink::ScreenOrientation {
public:
    void LockOrientation(::device::mojom::blink::ScreenOrientationLockType orientation, LockOrientationCallback callback) override
    {
        std::move(callback).Run(::device::mojom::ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS);
    }

    void UnlockOrientation() override {}
};

}

#endif // content_renderer_ClipboardHostImpl_h