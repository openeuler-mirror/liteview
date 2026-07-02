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


#include "content/ui/ContextMeun.h"

const char* createTempCharString(const char* str, size_t length);
const char16_t* createTempCharStringW(const char16_t* str, size_t length);

namespace content {

volatile long ContextMenu::m_isDestroyed = 0;
ContextMenu* ContextMenu::m_inst = nullptr;

uint32_t g_contextMenuItemMask = kMbMenuSelectedAllId | kMbMenuSelectedTextId | kMbMenuUndoId | kMbMenuCopyImageId | kMbMenuSaveImageId |
kMbMenuInspectElementAtId | kMbMenuCutId | kMbMenuPasteId;

/*constexpr*/ std::array<std::pair<int, const char*>, 12> kMenuItems = {
    {
        { kMbMenuSelectedAllId , "Selected All" },
        { kMbMenuSelectedTextId , "Copy" },
        { kMbMenuUndoId , "Undo" },
        { kMbMenuCopyImageId , "Copy Image" },
        { kMbMenuInspectElementAtId , "Inspect Element" },
        { kMbMenuCutId , "Cut" },
        { kMbMenuPasteId , "Paste" },
        { kMbMenuPrintId , "Print" },
        { kMbMenuGoForwardId, "Go Forward" },
        { kMbMenuGoBackId, "Go Back" },
        { kMbMenuReloadId, "Reload" },
        { kMbMenuSaveImageId, "Save Image" },
    }
};

ContextMenu* ContextMenu::get()
{
    if (!m_inst)
        m_inst = new ContextMenu();
    return m_inst;
}

bool ContextMenu::canShowItem(UINT actionFlags, mbMenuItemId id)
{
    if ((actionFlags & id) && (g_contextMenuItemMask & id))
        return true;
    return false;
}

void ContextMenu::executeMenuCommand(MbWebView* webview, UINT itemID)
{
    if (0 < ContextMenu::m_isDestroyed)
        return;

    ThreadCall::wake();

    if (kMbMenuSelectedTextId == itemID) {
        webview->getWebView()->FocusedFrame()->ExecuteCommand("Copy");
    } else if (kMbMenuSelectedAllId == itemID) {
        webview->getWebView()->FocusedFrame()->ExecuteCommand("SelectAll");
    } else if (kMbMenuUndoId == itemID) {
        webview->getWebView()->FocusedFrame()->ExecuteCommand("Undo");
    } else if (kMbMenuCopyImageId == itemID) {
        webview->getWebView()->FocusedFrame()->CopyImageAtForTesting(m_imagePos);
    } else if (kMbMenuSaveImageId == itemID) {
        //             if (!g_saveImageingWebPage) {
        //                 g_saveImageingWebPage = webview->webPageImpl();
        //                 webview->getWebView()->FocusedFrame()->CopyImageAt(m_imagePos);
        //             }
    } else if (kMbMenuInspectElementAtId == itemID) {
        //webview->InspectElementAt(m_data.mousePosition.x, m_data.mousePosition.y);
    } else if (kMbMenuCutId == itemID) {
        webview->getWebView()->FocusedFrame()->ExecuteCommand("Cut");
    } else if (kMbMenuPasteId == itemID) {
        webview->getWebView()->FocusedFrame()->ExecuteCommand("Paste");
    } else if (kMbMenuGoForwardId == itemID) {
        //webview->goForward();
        webview->navigateBackForwardSoon(1);
    } else if (kMbMenuGoBackId == itemID) {
        //webview->goBack();
        webview->navigateBackForwardSoon(-1);
    } else if (kMbMenuReloadId == itemID) {
        webview->getMainFrame()->ToWebLocalFrame()->StartReload(blink::WebFrameLoadType::kReload);
    } else if (kMbMenuPrintId == itemID) {
        //             wkeOnContextMenuItemClickCallback clickCallback = m_webview->wkeHandler().contextMenuItemClickCallback;
        //             void* callbackParam = m_webview->wkeHandler().contextMenuItemClickCallbackParam;
        //             if (clickCallback)
        //                 clickCallback(m_webview->wkeWebView(), callbackParam, kWkeContextMenuItemClickTypePrint, kWkeContextMenuItemClickStepClick, (wkeWebFrameHandle)m_frameId, nullptr);
    }
}

UINT ContextMenu::calcBlinkSupportedFlag(const blink::UntrustworthyContextMenuParams& data)
{
    UINT actionFlags = 0;
    if ((!data.selection_text.empty()))
        actionFlags |= kMbMenuSelectedTextId;

    if (data.has_image_contents) {
        actionFlags |= kMbMenuCopyImageId;
        actionFlags |= kMbMenuSaveImageId;
        m_imagePos = gfx::Point(data.x, data.y);
    }

    //if (m_webview->isDevtoolsConneted())
    //    actionFlags |= kInspectElementAtId;

    if (data.is_editable) {
        actionFlags |= kMbMenuCutId;
        actionFlags |= kMbMenuPasteId;
        actionFlags |= kMbMenuSelectedAllId;
        actionFlags |= kMbMenuUndoId;
    }

    if (m_webview->canGoForward())
        actionFlags |= kMbMenuGoForwardId;
    if (m_webview->canGoBack())
        actionFlags |= kMbMenuGoBackId;
    actionFlags |= kMbMenuReloadId;

    bool needCreatePrintItem = false;
    //         mbOnContextMenuItemClickCallback clickCallback = m_webview->wkeHandler().contextMenuItemClickCallback;
    //         void* callbackParam = m_webview->wkeHandler().contextMenuItemClickCallbackParam;
    //         if (clickCallback)
    //             needCreatePrintItem = clickCallback(m_webview->wkeWebView(), callbackParam, kWkeContextMenuItemClickTypePrint, kWkeContextMenuItemClickStepShow, (wkeWebFrameHandle)m_frameId, nullptr);

    if (needCreatePrintItem)
        actionFlags |= kMbMenuPrintId;

    return actionFlags;
}

void ContextMenu::blinkContextMenuParamsConvert(const blink::UntrustworthyContextMenuParams& inParams, mbContextMenuParams* outParams)
{
    outParams->structSize = sizeof(mbContextMenuParams);

    outParams->mediaType = kMbContextMenuDataMediaTypeNone;
    switch (inParams.media_type) {
        case blink::mojom::ContextMenuDataMediaType::kImage:
            outParams->mediaType = kMbContextMenuDataMediaTypeImage;
        case blink::mojom::ContextMenuDataMediaType::kVideo:
            outParams->mediaType = kMbContextMenuDataMediaTypeVideo;
        case blink::mojom::ContextMenuDataMediaType::kAudio:
            outParams->mediaType = kMbContextMenuDataMediaTypeAudio;
        case blink::mojom::ContextMenuDataMediaType::kCanvas:
            outParams->mediaType = kMbContextMenuDataMediaTypeCanvas;
        case blink::mojom::ContextMenuDataMediaType::kFile:
            outParams->mediaType = kMbContextMenuDataMediaTypeFile;
        case blink::mojom::ContextMenuDataMediaType::kPlugin:
            outParams->mediaType = kMbContextMenuDataMediaTypePlugin;
        default:
            break;
    }

    outParams->x = inParams.x;
    outParams->y = inParams.y;

    const std::string& linkUrl = inParams.link_url.possibly_invalid_spec();
    outParams->linkUrl = createTempCharString(linkUrl.c_str(), linkUrl.size());
    outParams->linkText = (const WCHAR*)createTempCharStringW(inParams.link_text.c_str(), inParams.link_text.size());

    const std::string& unfilteredLinkUrl = inParams.unfiltered_link_url.possibly_invalid_spec();
    outParams->unfilteredLinkUrl = createTempCharString(unfilteredLinkUrl.c_str(), unfilteredLinkUrl.size());

    const std::string& srcUrl = inParams.src_url.possibly_invalid_spec();
    outParams->srcUrl = createTempCharString(srcUrl.c_str(), srcUrl.size());
    outParams->hasImageContents = inParams.has_image_contents;
    outParams->isImageMediaPluginDocument = false;
    outParams->mediaFlags = inParams.media_flags;
    outParams->selectionText = (const WCHAR*)createTempCharStringW(inParams.selection_text.c_str(), inParams.selection_text.size());
    outParams->titleText = (const WCHAR*)createTempCharStringW(inParams.title_text.c_str(), inParams.title_text.size());
    outParams->altText = (const WCHAR*)createTempCharStringW(inParams.alt_text.c_str(), inParams.alt_text.size());
    outParams->suggestedFilename = (const WCHAR*)createTempCharStringW(inParams.suggested_filename.c_str(), inParams.suggested_filename.size());
    outParams->misspelledWord = (const WCHAR*)createTempCharStringW(inParams.misspelled_word.c_str(), inParams.misspelled_word.size());
    outParams->spellcheckEnabled = inParams.spellcheck_enabled;
    outParams->isEditable = inParams.is_editable;
}

bool ContextMenu::dispatchMbCallback(const UINT blinkSupportedFlag)
{
    BOOL needContinue = TRUE;
    if (m_webview->getClosure().m_ContextMenuPopupCallback) {
        std::vector<mbMenuItemId> ids;
        std::vector<const char*> labels;
        for (const auto& [id, label] : kMenuItems) {
            if (!canShowItem(blinkSupportedFlag, (mbMenuItemId)id))
                continue;

            ids.push_back((mbMenuItemId)id);
            labels.push_back(label);
        }

        if (!ids.empty()) {
            mbContextMenuParams menuParams;
            blinkContextMenuParamsConvert(m_data, &menuParams);

            needContinue = m_webview->getClosure().m_ContextMenuPopupCallback(m_webview->getId(),
                m_webview->getClosure().m_ContextMenuPopupParam,
                ids.size(), ids.data(), labels.data(), &menuParams);
        }
    }
    return needContinue;
}

void ContextMenu::onCommand(UINT itemID)
{
    executeMenuCommand(m_webview, itemID);
}

void clearMbWebViewInContextMenuIfNeeded(MbWebView* webview) {
    if (ContextMenu::get()->getCurrentWebview() == webview)
        ContextMenu::get()->setCurrentWebview(nullptr);
}

}