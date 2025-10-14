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


#ifndef content_browser_time_zone_monitor_h
#define content_browser_time_zone_monitor_h

#include "services/device/public/mojom/time_zone_monitor.mojom-blink.h"
#include "mojo/public/cpp/bindings/receiver.h"

namespace content {

class TimeZoneMonitorImpl : public device::mojom::blink::TimeZoneMonitor {
public:
    void AddClient(::mojo::PendingRemote<device::mojom::blink::TimeZoneMonitorClient> client) override
    {
//         device::mojom::blink::TimeZoneMonitorClient** ptr_addr = client.PassPtrAddrT();
//         device::mojom::blink::TimeZoneMonitorClient* client2 = (*ptr_addr);
        //OutputDebugStringA("TimeZoneMonitorImpl::AddClient not impl\n");
    }

    mojo::Receiver<device::mojom::blink::TimeZoneMonitor> m_receiver{ this };
};

}

#endif // content_browser_time_zone_monitor_h