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


#include "third_party/blink/public/mojom/plugins/plugin_registry.mojom-blink.h"

bool blink::mojom::blink::PluginRegistry::GetPlugins(bool refresh, WTF::Vector< ::blink::mojom::blink::PluginInfoPtr>*)
{
    *(int*)1 = 1;
    return true;
}

namespace content {

class PluginRegistryImpl : public ::blink::mojom::blink::PluginRegistry {
public:
    bool GetPlugins(bool refresh, WTF::Vector< ::blink::mojom::blink::PluginInfoPtr>* out_plugins) override
    {
        return true;
    }

    //using GetPluginsCallback = base::OnceCallback<void(WTF::Vector<PluginInfoPtr>)>;
    void GetPlugins(bool refresh, ::blink::mojom::blink::PluginRegistry::GetPluginsCallback callback) override
    {
        WTF::Vector<::blink::mojom::blink::PluginInfoPtr> pluginInfo;
        std::move(callback).Run(std::move(pluginInfo));
    }
};

}