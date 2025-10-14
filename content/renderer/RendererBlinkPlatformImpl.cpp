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


#include "content/renderer/RendererBlinkPlatformImpl.h"

#include "content/renderer/BlobRegistryImpl.h"
#include "content/renderer/PluginRegistryImpl.h"
#include "content/renderer/WebDedicatedWorkerHostFactoryClientImpl.h"
#include "content/renderer/V8ValueConverterImpl.h"
#include "content/renderer/Webgraphicscontext3dProviderImpl.h"
#include "content/browser/TimeZoneMonitorImpl.h"
#include "content/browser/DomStorageProviderImpl.h"
#include "content/resources/HtmlFormsResources.h"
#include "content/resources/res.h"
#include "content/resources/ImageRes.h"
#include "content/resources/MediaControls.h"
#include "content/common/CreateAndBindTempl.h"
#include "mbnet/LoaderFactoryImpl.h"
#include "components/webcrypto/webcrypto_impl.h"
#include "third_party/blink/public/platform/web_url_loader_factory.h"
#include "third_party/blink/public/platform/web_back_forward_cache_loader_helper.h"

#include "third_party/blink/public/common/thread_safe_browser_interface_broker_proxy.h"
#include "third_party/blink/public/common/user_agent/user_agent_metadata.h"
#include "third_party/blink/public/mojom/mime/mime_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/blob/blob_registry.mojom-blink.h"
#include "third_party/blink/public/mojom/gpu/gpu.mojom-blink.h"
#include "third_party/blink/public/resources/grit/blink_resources.h"
#include "third_party/blink/public/resources/grit/blink_image_resources.h"
#include "third_party/blink/public/strings/grit/blink_strings.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/modules/media_controls/resources/grit/media_controls_resources.h"
#include "mojo/public/cpp/bindings/generic_pending_receiver.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"
#include <map>
#include <windows.h>

bool blink::mojom::blink::MimeRegistry::GetMimeTypeFromExtension(WTF::String const&, WTF::String*)
{
    *(int*)1 = 1;
    return false;
}

bool blink::mojom::blink::GpuDataManager::Are3DAPIsBlockedForUrl(const ::blink::KURL&, bool*)
{
    *(int*)1 = 1;
    return false;
}

namespace content {

//////////////////////////////////////////////////////////////////////////
class MimeRegistryImpl : public ::blink::mojom::blink::MimeRegistry {
public:
    MimeRegistryImpl()
    {

    }

    bool GetMimeTypeFromExtension(const WTF::String& extension, WTF::String* out_mime_type) override
    {
        if (WTF::EqualIgnoringASCIICase(extension, "css")) {
            *out_mime_type = "text/css";
            return true;
        } else if (WTF::EqualIgnoringASCIICase(extension, "js")) {
            *out_mime_type = "text/javascript";
            return true;
        } else if (WTF::EqualIgnoringASCIICase(extension, "html") || WTF::EqualIgnoringASCIICase(extension, "htm")) {
            *out_mime_type = "text/html";
            return true;
        } else if (WTF::EqualIgnoringASCIICase(extension, "svg")) {
            *out_mime_type = "image/svg+xml";
            return true;
        } else if (WTF::EqualIgnoringASCIICase(extension, "webp")) {
            *out_mime_type = "image/webp";
            return true;
        } else if (WTF::EqualIgnoringASCIICase(extension, "png")) {
            *out_mime_type = "image/png";
            return true;
        }

        std::string out = "GetMimeTypeFromExtension fail:";
        out += extension.Ascii();
        out += "\n";
        OutputDebugStringA(out.c_str());
        return false;
    }

    //using GetMimeTypeFromExtensionCallback = base::OnceCallback<void(const WTF::String&)>;
    void GetMimeTypeFromExtension(const WTF::String& extension, GetMimeTypeFromExtensionCallback callback) override
    {

    }

    mojo::Receiver<blink::mojom::blink::MimeRegistry> m_receiver{this};
};

class GpuDataManagerImpl : public ::blink::mojom::blink::GpuDataManager {
    /*virtual*/ bool Are3DAPIsBlockedForUrl(const ::blink::KURL& url, bool* outBlocked) override
    {
        *outBlocked = false;
        return true;
    }

    //using Are3DAPIsBlockedForUrlCallback = base::OnceCallback<void(bool)>;
    /*virtual*/ void Are3DAPIsBlockedForUrl(const ::blink::KURL& url, Are3DAPIsBlockedForUrlCallback callback) override
    {
        std::move(callback).Run(false);
    }
};
//////////////////////////////////////////////////////////////////////////

class BrowserInterfaceBrokerProxy : public blink::ThreadSafeBrowserInterfaceBrokerProxy {
public:
    BrowserInterfaceBrokerProxy() = default;

    // ThreadSafeBrowserInterfaceBrokerProxy implementation:
    void GetInterfaceImpl(mojo::GenericPendingReceiver receiver) override
    {
        CHECK(receiver.interface_name().has_value());

        std::string output("BrowserInterfaceBrokerProxy:");
        output += receiver.interface_name().has_value() ? receiver.interface_name().value() : "no name";
        output += "\n";
        OutputDebugStringA(output.c_str());

        if ("device.blink.mojom.TimeZoneMonitor" == receiver.interface_name().value()) {
            if (!m_timeZoneMonitorImpl)
                m_timeZoneMonitorImpl = new TimeZoneMonitorImpl();
            m_timeZoneMonitorImpl->m_receiver.Bind(receiver.As<device::mojom::blink::TimeZoneMonitor>());
            return;
        } else if ("blink.mojom.MimeRegistry" == receiver.interface_name().value()) {
            if (!m_imeRegistryImpl)
                m_imeRegistryImpl = new MimeRegistryImpl();
            m_imeRegistryImpl->m_receiver.Bind(receiver.As<blink::mojom::blink::MimeRegistry>());
            return;
        } else if ("blink.mojom.BlobRegistry" == receiver.interface_name().value()) {
//             if (!m_blobRegistry)
//                 m_blobRegistry = new BlobRegistryImpl();
//             m_blobRegistry->m_receiver.Bind(receiver.As<::blink::mojom::blink::BlobRegistry>());
            createAndBindBrokerProxy<::blink::mojom::blink::BlobRegistry, BlobRegistryImpl>(receiver.PassPipe());
            return;
        } else if ("blink.mojom.DomStorageProvider" == receiver.interface_name().value()) {
            createAndBindBrokerProxy<::blink::mojom::blink::DomStorageProvider, DomStorageProviderImpl>(receiver.PassPipe());
            return;
        } else if ("blink.mojom.PluginRegistry" == receiver.interface_name().value()) {
            createAndBindBrokerProxy<::blink::mojom::blink::PluginRegistry, PluginRegistryImpl>(receiver.PassPipe());
            return;
        } else if ("blink.mojom.GpuDataManager" == receiver.interface_name().value()) {
            createAndBindBrokerProxy<::blink::mojom::blink::GpuDataManager, GpuDataManagerImpl>(receiver.PassPipe());
            return;
        }
        DebugBreak();
    }

private:
    ~BrowserInterfaceBrokerProxy() override = default;

    std::map<std::string, void*> m_interfaces;

    TimeZoneMonitorImpl* m_timeZoneMonitorImpl = nullptr;
    MimeRegistryImpl* m_imeRegistryImpl = nullptr;
    //BlobRegistryImpl* m_blobRegistry = nullptr;
};

// class WebURLLoaderFactoryImpl : public blink::WebURLLoaderFactory {
// public:
//     std::unique_ptr<blink::WebURLLoader> CreateURLLoader(const blink::WebURLRequest& webreq,
//         std::unique_ptr<blink::scheduler::WebResourceLoadingTaskRunnerHandle> freezable_task_runner,
//         std::unique_ptr<blink::scheduler::WebResourceLoadingTaskRunnerHandle> unfreezable_task_runner,
//         blink::CrossVariantMojoRemote<blink::mojom::KeepAliveHandleInterfaceBase> keep_alive_handle,
//         blink::WebBackForwardCacheLoaderHelper back_forward_cache_loader_helper) override
//     {
//         DebugBreak();
//     }
// };


scoped_refptr<base::SingleThreadTaskRunner> RendererBlinkPlatformImpl::GetIOTaskRunner() const 
{
    return m_ioThread.task_runner();
}

// from LoaderFactoryForFrame::CreateURLLoader
std::unique_ptr<blink::WebURLLoaderFactory> RendererBlinkPlatformImpl::WrapURLLoaderFactory(
    blink::CrossVariantMojoRemote<network::mojom::URLLoaderFactoryInterfaceBase> url_loader_factory)
{
    return std::make_unique<mbnet::LoaderFactoryImpl>();
}

blink::ThreadSafeBrowserInterfaceBrokerProxy* RendererBlinkPlatformImpl::GetBrowserInterfaceBroker()
{
    DEFINE_STATIC_LOCAL(BrowserInterfaceBrokerProxy, proxy, ());
    return &proxy;
}

// Returns a value such as "en-US".
blink::WebString RendererBlinkPlatformImpl::DefaultLocale() { return blink::WebString::FromUTF8("zh-CN"); }

std::unique_ptr<blink::URLLoaderThrottleProvider> RendererBlinkPlatformImpl::CreateURLLoaderThrottleProviderForWorker(
    blink::URLLoaderThrottleProviderType provider_type)
{
    //     return GetContentClient()->renderer()->CreateURLLoaderThrottleProvider(
    //         blink::URLLoaderThrottleProviderType::kWorker);
    DebugBreak();
    return nullptr;
}

blink::WebData RendererBlinkPlatformImpl::GetDataResource(int resource_id, ui::ResourceScaleFactor scale_factor)
{
    if (IDR_BROKENIMAGE == resource_id) {
        return blink::WebData((const char*)kBrokenImage14x16, 448);
    }
    return blink::WebData();
}

#define MAKE_STRING_CASE(id) case id: return std::string((const char*)(k##id), sizeof(k##id));
#define MAKE_STD_STRING(str) std::string((const char*)(str), sizeof(str));

std::string RendererBlinkPlatformImpl::GetDataResourceString(int resourceId)
{
    switch (resourceId) {
    case IDR_UASTYLE_HTML_CSS:
        return kIDR_UASTYLE_HTML_CSS;
    case IDR_UASTYLE_THEME_INPUT_MULTIPLE_FIELDS_CSS:
        return kIDR_UASTYLE_THEME_INPUT_MULTIPLE_FIELDS_CSS;
    case IDR_UASTYLE_QUIRKS_CSS:
        return kIDR_UASTYLE_QUIRKS_CSS;
    case IDR_UASTYLE_MARKER_CSS:
        return kIDR_UASTYLE_MARKER_CSS;
    case IDR_UASTYLE_SVG_CSS:
        return kIDR_UASTYLE_SVG_CSS;
    case IDR_UASTYLE_THEME_CHROMIUM_LINUX_CSS: // third_party/blink/renderer/core/html/resources/linux.css
        return "select:not(:-internal-list-box) {background-color: ButtonFace;}input[type=range i] {color: #9d968E;}";
    case IDR_UASTYLE_MATHML_CSS:
        return MAKE_STD_STRING(kMathmlCss);
    case IDR_UASTYLE_MATHML_FALLBACK_CSS:
        return MAKE_STD_STRING(kMathmlFallbackCss);
    case IDR_DOCUMENTXMLTREEVIEWER_JS:
        return MAKE_STD_STRING(kDocumentXMLTreeViewerJs);
    case IDR_DOCUMENTXMLTREEVIEWER_CSS:
        return MAKE_STD_STRING(kDocumentXMLTreeViewerCss);
    case IDR_UASTYLE_VIEW_SOURCE_CSS:
        return MAKE_STD_STRING(kViewSourceCss);        
    MAKE_STRING_CASE(IDR_SHADOWSTYLE_MEDIA_CONTROLS_ANIMATED_ARROW_CSS);
    MAKE_STRING_CASE(IDR_UASTYLE_MEDIA_INTERSTITIALS_CSS);
    MAKE_STRING_CASE(IDR_SHADOWSTYLE_MEDIA_CONTROLS_SCRUBBING_MESSAGE_CSS);
    MAKE_STRING_CASE(IDR_UASTYLE_MEDIA_CONTROLS_CSS);
    MAKE_STRING_CASE(IDR_SHADOWSTYLE_MEDIA_CONTROLS_LOADING_CSS);
    case IDR_CALENDAR_PICKER_CSS:
        return MAKE_STD_STRING(kCalendarPickerCss);
    case IDR_CALENDAR_PICKER_JS:
        return MAKE_STD_STRING(kCalendarPickerJs);
    case IDR_COLOR_PICKER_CSS:
        return MAKE_STD_STRING(kColorPickerCss);
    case IDR_COLOR_PICKER_JS:
        return MAKE_STD_STRING(kColorPickerJs);
    case IDR_COLOR_PICKER_COMMON_JS:
        return MAKE_STD_STRING(kColorPickerCommonJs);
    case IDR_COLOR_SUGGESTION_PICKER_CSS:
        return MAKE_STD_STRING(kColorSuggestionPickerCss);
    case IDR_COLOR_SUGGESTION_PICKER_JS:
        return MAKE_STD_STRING(kColorSuggestionPickerJs);
    case IDR_DATETIMELOCAL_PICKER_JS:
        return MAKE_STD_STRING(kDatetimelocalPickerJs);
    case IDR_LIST_PICKER_CSS:
        return MAKE_STD_STRING(kListPickerCss);
    case IDR_LIST_PICKER_JS:
        return MAKE_STD_STRING(kListPickerJs);
    case IDR_MONTH_PICKER_JS:
        return MAKE_STD_STRING(kMonthPickerJs);
    case IDR_PICKER_COMMON_CSS:
        return MAKE_STD_STRING(kPickerCommonCss);
    case IDR_PICKER_COMMON_JS:
        return MAKE_STD_STRING(kPickerCommonJs);
    case IDR_SUGGESTION_PICKER_CSS:
        return MAKE_STD_STRING(kSuggestionPickerCss);
    case IDR_SUGGESTION_PICKER_JS:
        return MAKE_STD_STRING(kSuggestionPickerJs);
    case IDR_TIME_PICKER_CSS:
        return MAKE_STD_STRING(kTimePickerCss);
    case IDR_TIME_PICKER_JS:
        return MAKE_STD_STRING(kTimePickerJs);
    case IDR_VALIDATION_BUBBLE_CSS:
        return MAKE_STD_STRING(kValidationBubbleCss);
    }
    DebugBreak();
    return "";
}

blink::WebString RendererBlinkPlatformImpl::QueryLocalizedString(int resourceId) 
{
    switch (resourceId) {
        case IDS_FORM_MULTIPLE_FILES_BUTTON_LABEL:
        case IDS_FORM_FILE_BUTTON_LABEL:
            return blink::WebString::FromUTF8("select");
        case IDS_FORM_FILE_NO_FILE_LABEL:
            return blink::WebString::FromUTF8("no file");
        case IDS_AX_MEDIA_LOADING_PANEL:
            return blink::WebString::FromUTF8("media loading..");
        case IDS_AX_MEDIA_CAST_ON_BUTTON:
            return blink::WebString::FromUTF8("cast on button");
        case IDS_AX_MEDIA_CAST_OFF_BUTTON:
            return blink::WebString::FromUTF8("cast off button");
        case IDS_AX_MEDIA_EXIT_FULL_SCREEN_BUTTON:
            return blink::WebString::FromUTF8("exit full screen");
        case IDS_AX_MEDIA_ENTER_FULL_SCREEN_BUTTON:
            return blink::WebString::FromUTF8("enter full screen");
        case IDS_AX_MEDIA_DOWNLOAD_BUTTON:
            return blink::WebString::FromUTF8("download");
        case IDS_AX_MEDIA_SHOW_CLOSED_CAPTIONS_MENU_BUTTON:
            return blink::WebString::FromUTF8("show closed captions");
        case IDS_AX_MEDIA_SHOW_PLAYBACK_SPEED_MENU_BUTTON:
            return blink::WebString::FromUTF8("show playback speed");
        case IDS_AX_MEDIA_OVERFLOW_BUTTON:
            return blink::WebString::FromUTF8("overflow");
        case IDS_AX_MEDIA_OVERFLOW_BUTTON_HELP:
            return blink::WebString::FromUTF8("overflow help");
        case IDS_MEDIA_OVERFLOW_MENU_CLOSED_CAPTIONS_SUBMENU_TITLE:
            return blink::WebString::FromUTF8("overflow closed captions");
        case IDS_MEDIA_OVERFLOW_MENU_PLAYBACK_SPEED_SUBMENU_TITLE:
            return blink::WebString::FromUTF8("overflow playback speed");
        case IDS_MEDIA_OVERFLOW_MENU_PLAY:
            return blink::WebString::FromUTF8("play");
        case IDS_MEDIA_OVERFLOW_MENU_PAUSE:
            return blink::WebString::FromUTF8("pause");
        case IDS_MEDIA_OVERFLOW_MENU_EXIT_FULLSCREEN:
            return blink::WebString::FromUTF8("exit fullscreen");
        case IDS_MEDIA_OVERFLOW_MENU_ENTER_FULLSCREEN:
            return blink::WebString::FromUTF8("enter fullscreen");
        case IDS_MEDIA_OVERFLOW_MENU_DOWNLOAD:
            return blink::WebString::FromUTF8("download");
        case IDS_MEDIA_OVERFLOW_MENU_UNMUTE:
            return blink::WebString::FromUTF8("unmute");
        case IDS_MEDIA_OVERFLOW_MENU_MUTE:
            return blink::WebString::FromUTF8("mute");
        case IDS_MEDIA_OVERFLOW_MENU_CAST:
            return blink::WebString::FromUTF8("cast");
        case IDS_MEDIA_OVERFLOW_MENU_CLOSED_CAPTIONS:
            return blink::WebString::FromUTF8("closed captions");
        case IDS_MEDIA_OVERFLOW_MENU_PLAYBACK_SPEED:
            return blink::WebString::FromUTF8("playback speed");
        case IDS_AX_MEDIA_PLAY_BUTTON:
            return blink::WebString::FromUTF8("play");
        case IDS_AX_MEDIA_PAUSE_BUTTON:
            return blink::WebString::FromUTF8("pause");
        case IDS_AX_MEDIA_VIDEO_SLIDER_HELP:
            return blink::WebString::FromUTF8("video slider");
        case IDS_AX_MEDIA_AUDIO_SLIDER_HELP:
            return blink::WebString::FromUTF8("audio slider");
        case IDS_AX_MEDIA_UNMUTE_BUTTON:
            return blink::WebString::FromUTF8("unmute");
        case IDS_AX_MEDIA_MUTE_BUTTON:
            return blink::WebString::FromUTF8("mute");
        case IDS_DETAILS_WITHOUT_SUMMARY_LABEL:
            return blink::WebString::FromUTF8("without summary");
        case IDS_FORM_PLACEHOLDER_FOR_DAY_OF_MONTH_FIELD:
            return blink::WebString::FromUTF8("day of month");
        case IDS_FORM_PLACEHOLDER_FOR_MONTH_FIELD:
            return blink::WebString::FromUTF8("month");
        case IDS_FORM_PLACEHOLDER_FOR_YEAR_FIELD:
            return blink::WebString::FromUTF8("year");
        case IDS_AX_YEAR_FIELD_TEXT:
            return blink::WebString::FromUTF8("year");
        case IDS_AX_MONTH_FIELD_TEXT:
            return blink::WebString::FromUTF8("month");
        case IDS_AX_DAY_OF_MONTH_FIELD_TEXT:
            return blink::WebString::FromUTF8("day of month");
        case IDS_FORM_INPUT_WEEK_TEMPLATE:
            return blink::WebString::FromUTF8("week");
        case IDS_AX_WEEK_OF_YEAR_FIELD_TEXT:
            return blink::WebString::FromUTF8("week of year");
        case IDS_AX_HOUR_FIELD_TEXT:
            return blink::WebString::FromUTF8("hour");
        case IDS_AX_MINUTE_FIELD_TEXT:
            return blink::WebString::FromUTF8("minute");
        case IDS_FORM_INPUT_ALT:
            return blink::WebString::FromUTF8("alt");
        case IDS_FORM_SUBMIT_LABEL:
            return blink::WebString::FromUTF8("submit");
        case IDS_FORM_VALIDATION_VALUE_MISSING:
            return blink::WebString::FromUTF8("validation value missing");
        case IDS_MEDIA_TRACKS_OFF:
            return blink::WebString::FromUTF8("tracks off");
        case IDS_FORM_RESET_LABEL:
            return blink::WebString::FromUTF8("reset");
        case IDS_FORM_VALIDATION_PATTERN_MISMATCH:
            return blink::WebString::FromUTF8("mismatch");
        case IDS_AX_CALENDAR_SHOW_DATE_PICKER:
            return blink::WebString::FromUTF8("ax calendar show date picker");
        case IDS_AX_CALENDAR_SHOW_DATE_TIME_LOCAL_PICKER:
            return blink::WebString::FromUTF8("ax calendar show date time local picker");
        case IDS_FORM_CALENDAR_TODAY:
            return blink::WebString::FromUTF8("today");
        case IDS_FORM_OTHER_DATE_LABEL:
            return blink::WebString::FromUTF8("other date");
        case IDS_FORM_CALENDAR_CLEAR:
            return blink::WebString::FromUTF8("calendar clear");
        case IDS_FORM_WEEK_NUMBER_LABEL:
            return blink::WebString::FromUTF8("week number");
        case IDS_AX_CALENDAR_SHOW_MONTH_SELECTOR:
            return blink::WebString::FromUTF8("calendar show month");
        case IDS_AX_CALENDAR_SHOW_NEXT_MONTH:
            return blink::WebString::FromUTF8("calendar show next");
        case IDS_AX_CALENDAR_SHOW_PREVIOUS_MONTH:
            return blink::WebString::FromUTF8("calendar show previous");
        case IDS_AX_SECOND_FIELD_TEXT:
            return blink::WebString::FromUTF8("second field");
        case IDS_AX_MILLISECOND_FIELD_TEXT:
            return blink::WebString::FromUTF8("millisecond field");
        case IDS_AX_AM_PM_FIELD_TEXT:
            return blink::WebString::FromUTF8("AM PM field");
        case IDS_AX_MEDIA_EXIT_PICTURE_IN_PICTURE_BUTTON:
            return blink::WebString::FromUTF8("exit picture in picture");
        case IDS_AX_MEDIA_ENTER_PICTURE_IN_PICTURE_BUTTON:
            return blink::WebString::FromUTF8("enter picture in picture");
        case IDS_MEDIA_OVERFLOW_MENU_EXIT_PICTURE_IN_PICTURE:
            return blink::WebString::FromUTF8("exit picture in picture");
        case IDS_MEDIA_OVERFLOW_MENU_ENTER_PICTURE_IN_PICTURE:
            return blink::WebString::FromUTF8("enter picture in picture");

        case IDS_AX_COLOR_WELL:
            return blink::WebString::FromUTF8("Color Well");
        case IDS_AX_COLOR_WELL_ROLEDESCRIPTION:
            return blink::WebString::FromUTF8("Color Well Role Description");
        case IDS_AX_COLOR_HUE_SLIDER:
            return blink::WebString::FromUTF8("Hue Slider");
        case IDS_AX_COLOR_EDIT_HEXADECIMAL:
            return blink::WebString::FromUTF8("Hexadecimal Edit");
        case IDS_AX_COLOR_EDIT_RED:
            return blink::WebString::FromUTF8("Red Edit");
        case IDS_AX_COLOR_EDIT_GREEN:
            return blink::WebString::FromUTF8("Green Edit");
        case IDS_AX_COLOR_EDIT_BLUE:
            return blink::WebString::FromUTF8("Blue Edit");
        case IDS_AX_COLOR_EDIT_HUE:
            return blink::WebString::FromUTF8("Hue Edit");
        case IDS_AX_COLOR_EDIT_SATURATION:
            return blink::WebString::FromUTF8("Saturation Edit");
        case IDS_AX_COLOR_EDIT_LIGHTNESS:
            return blink::WebString::FromUTF8("Lightness Edit");
        case IDS_AX_COLOR_FORMAT_TOGGLER:
            return blink::WebString::FromUTF8("Format Toggler");
        case IDS_AX_COLOR_EYEDROPPER:
            return blink::WebString::FromUTF8("Eyedropper");
        default:
            break;
    }

    DebugBreak();
    return blink::WebString();
}

blink::WebString RendererBlinkPlatformImpl::QueryLocalizedString(int resourceId, const blink::WebString& parameter)
{
    switch (resourceId) {
    case IDS_AX_MEDIA_CURRENT_TIME_DISPLAY:
    case IDS_AX_MEDIA_TIME_REMAINING_DISPLAY:
        return parameter;
    default:
        break;
    }

    DebugBreak();
    return blink::WebString();
}

blink::WebString RendererBlinkPlatformImpl::QueryLocalizedString(int resourceId, const blink::WebString& parameter1, const blink::WebString& parameter2)
{
    if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL_NO_AT_SIGN == resourceId) {
        return String::Format("Please include an '%s@' in the email address. 'user' is missing an '%s@", parameter1.Utf8().c_str(), parameter1.Utf8().c_str());
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL_EMPTY_LOCAL == resourceId) {
        return String::Format("Please enter a part followed by '%s@'. '%s@example.com' is incomplete.", parameter1.Utf8().c_str(), parameter2.Utf8().c_str());
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL_EMPTY_DOMAIN == resourceId) {
        return String::Format("Please enter a part following '%s@'. '%s@' is incomplete.", parameter1.Utf8().c_str(), parameter2.Utf8().c_str());
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL_INVALID_LOCAL == resourceId) {
        return String::Format("A part followed by '%s' should not contain the symbol '%s", parameter1.Utf8().c_str(), parameter2.Utf8().c_str());
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL_INVALID_DOMAIN == resourceId) {
        return String::Format("A part following '%s' should not contain the symbol '%s'", parameter1.Utf8().c_str(), parameter2.Utf8().c_str());
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL_INVALID_DOTS == resourceId) {
        return String::Format("'%s.' is used at a wrong position in '%s example..com'", parameter1.Utf8().c_str(), parameter2.Utf8().c_str());
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_MULTIPLE_EMAIL == resourceId) {
        return blink::WebString::FromUTF8("Please enter a comma separated list of email addresses.");
    } else if (IDS_FORM_VALIDATION_TYPE_MISMATCH_EMAIL == resourceId) {
        return blink::WebString::FromUTF8("Please enter an email address.");
    }

    DebugBreak();
    return blink::WebString();
}

//const char* s_ua = "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like XSD) Chrome/79.0.3945.130 Safari/537.36";
std::string* s_ua = nullptr;

RendererBlinkPlatformImpl::RendererBlinkPlatformImpl() :
    m_ioThread("ioThreadInPlatfrom")
{
    s_ua = new std::string();
    *s_ua = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36";

#if defined(ENABLE_MB_MEDIA) 
    m_ioThread.Start();
#endif // ENABLE_MB_MEDIA
}

void RendererBlinkPlatformImpl::setUserAgent(const std::string& ua)
{
    *s_ua = ua;
}

blink::WebString RendererBlinkPlatformImpl::UserAgent()
{
    return blink::WebString::FromASCII(*s_ua);
    //return blink::WebString::FromASCII("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36");
}

blink::WebString RendererBlinkPlatformImpl::FullUserAgent()
{
    return blink::WebString::FromASCII(*s_ua);
    //return blink::WebString::FromASCII("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36");
}

blink::WebString RendererBlinkPlatformImpl::ReducedUserAgent()
{
    return blink::WebString::FromASCII(*s_ua);
    //return blink::WebString::FromASCII("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36");
}

blink::UserAgentMetadata RendererBlinkPlatformImpl::UserAgentMetadata()
{
    blink::UserAgentMetadata ua;
  
    blink::UserAgentBrandVersion v;
    v.brand = "Not\\/A)Brand";
    v.version = "92";
    ua.brand_version_list.push_back(v);

    v.brand = "Chromium";
    v.version = "108";
    ua.brand_version_list.push_back(v);

    v.brand = "Google Chrome";
    v.version = "108";
    ua.brand_version_list.push_back(v);
    //UserAgentBrandList brand_full_version_list;

    ua.full_version = "108.0.5359.125";
    ua.platform = "Windows";
    ua.platform_version = "10.0.0";
    ua.architecture = "x86";
    ua.model = "";
    ua.mobile = false;
    ua.bitness = "64";
    ua.wow64 = false;

    return ua;
}

blink::WebCrypto* RendererBlinkPlatformImpl::Crypto()
{
    if (!m_webCryptoImpl)
        m_webCryptoImpl = new webcrypto::WebCryptoImpl();
    return m_webCryptoImpl;
}

// web worker
std::unique_ptr<blink::WebDedicatedWorkerHostFactoryClient> RendererBlinkPlatformImpl::CreateDedicatedWorkerHostFactoryClient(
    blink::WebDedicatedWorker* worker, const blink::BrowserInterfaceBrokerProxy&)
{
    return std::make_unique<WebDedicatedWorkerHostFactoryClientImpl>(worker);
}

void RendererBlinkPlatformImpl::DidStartWorkerThread()
{
    //OutputDebugStringA("RendererBlinkPlatformImpl::DidStartWorkerThread not impl\n");
}

void RendererBlinkPlatformImpl::WillStopWorkerThread()
{
    //OutputDebugStringA("RendererBlinkPlatformImpl::WillStopWorkerThread not impl\n");
}

void RendererBlinkPlatformImpl::WorkerContextCreated(const v8::Local<v8::Context>& worker)
{
    //OutputDebugStringA("RendererBlinkPlatformImpl::WorkerContextCreated not impl\n");
}

bool RendererBlinkPlatformImpl::AllowScriptExtensionForServiceWorker(const blink::WebSecurityOrigin& script_origin)
{
    return true;
}

blink::ProtocolHandlerSecurityLevel RendererBlinkPlatformImpl::GetProtocolHandlerSecurityLevel()
{
    return blink::ProtocolHandlerSecurityLevel::kStrict;
}

bool RendererBlinkPlatformImpl::OriginCanAccessServiceWorkers(const blink::WebURL& url)
{
    return true;
}

std::tuple<blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase>,
    blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase>>
    RendererBlinkPlatformImpl::CloneServiceWorkerContainerHost(
        blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase> service_worker_container_host)
{
    return std::make_tuple(
        /*original_service_worker_container_host=*/blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase>(),
        /*cloned_service_worker_container_host=*/blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase>());
}

void RendererBlinkPlatformImpl::CreateServiceWorkerSubresourceLoaderFactory(
    blink::CrossVariantMojoRemote<blink::mojom::ServiceWorkerContainerHostInterfaceBase> service_worker_container_host, const blink::WebString& client_id,
    std::unique_ptr<network::PendingSharedURLLoaderFactory> fallback_factory, mojo::PendingReceiver<network::mojom::URLLoaderFactory> receiver,
    scoped_refptr<base::SequencedTaskRunner> task_runner)
{
    DebugBreak();
}

std::unique_ptr<blink::WebV8ValueConverter> RendererBlinkPlatformImpl::CreateWebV8ValueConverter() 
{
    return std::make_unique<V8ValueConverterImpl>();
}

std::unique_ptr<blink::WebGraphicsContext3DProvider> RendererBlinkPlatformImpl::CreateOffscreenGraphicsContext3DProvider(
    const blink::Platform::ContextAttributes& web_attributes, 
    const blink::WebURL& topDocumentUrl, 
    blink::Platform::GraphicsInfo* gl_info)
{
#if SK_SUPPORT_GPU
    return std::make_unique<WebGraphicsContext3DProviderImpl>();
#endif

//     scoped_refptr<gpu::GpuChannelHost> gpu_channel_host(RenderThreadImpl::current()->EstablishGpuChannelSync());
//     if (!gpu_channel_host) {
//         std::string error_message("OffscreenContext Creation failed, GpuChannelHost creation failed");
//         gl_info->error_message = WebString::FromUTF8(error_message);
//         return nullptr;
//     }
//     Collect3DContextInformation(gl_info, gpu_channel_host->gpu_info());
// 
//     gpu::ContextCreationAttribs attributes;
//     attributes.bind_generates_resource = false;
//     attributes.enable_raster_interface = web_attributes.enable_raster_interface;
//     attributes.enable_oop_rasterization = attributes.enable_raster_interface &&
//         gpu_channel_host->gpu_feature_info().status_values[gpu::GPU_FEATURE_TYPE_CANVAS_OOP_RASTERIZATION] == gpu::kGpuFeatureStatusEnabled;
//     attributes.enable_gles2_interface = !attributes.enable_oop_rasterization;
//     attributes.enable_grcontext = !attributes.enable_oop_rasterization && web_attributes.support_grcontext;
// 
//     attributes.gpu_preference = web_attributes.prefer_low_power_gpu
//         ? gl::GpuPreference::kLowPower
//         : gl::GpuPreference::kHighPerformance;
// 
//     attributes.fail_if_major_perf_caveat = web_attributes.fail_if_major_performance_caveat;
// 
//     attributes.context_type = ToGpuContextType(web_attributes.context_type);
// 
//     constexpr bool automatic_flushes = true;
//     constexpr bool support_locking = false;
// 
//     return std::make_unique<WebGraphicsContext3DProviderImpl>(
//         base::MakeRefCounted<viz::ContextProviderCommandBuffer>(
//             std::move(gpu_channel_host), kGpuStreamIdDefault,
//             kGpuStreamPriorityDefault, gpu::kNullSurfaceHandle,
//             GURL(document_url), automatic_flushes, support_locking,
//             gpu::SharedMemoryLimits(), attributes,
//             viz::command_buffer_metrics::ContextType::WEBGL));
// 
//     return nullptr;
}

std::unique_ptr<blink::WebGraphicsContext3DProvider> RendererBlinkPlatformImpl::CreateSharedOffscreenGraphicsContext3DProvider()
{
    return nullptr;
}


}