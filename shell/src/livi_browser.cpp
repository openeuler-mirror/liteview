#include <stdio.h>
#include <stdlib.h>

#include "livi_browser_p.h"
#include "livi_download_manager.h"
#include "livi_ui_thread.h"
#include "utils/arguments.h"
#include "utils/runtime_info.h"

namespace livi {

static const char* browser_home_page = "https://isrc.iscas.ac.cn/";

static BrowserPage* browserCurrentPage(Browser* browser)
{
    guint index = gtk_notebook_get_current_page(GTK_NOTEBOOK(browser->page_notebook));
    return browser->page_list[index];
}

static bool browserPageIsCurrent(BrowserPage* page)
{
    guint n = gtk_notebook_get_current_page(GTK_NOTEBOOK(page->browser->page_notebook));
    return gtk_notebook_get_nth_page(GTK_NOTEBOOK(page->browser->page_notebook), n) == page->body;
}

static void browserPageSetTitle(BrowserPage* page, const char* title)
{
    page->title = title;
    gtk_label_set_label(GTK_LABEL(page->tab_title), title);
}

static void browserPageSetUrl(BrowserPage* page, const char* url, bool can_back = false, bool can_forward = false)
{
    page->url = url;
    page->can_back = can_back;
    page->can_forward = can_forward;
}

static void browserUpdateTitle(BrowserPage* page)
{
    gtk_window_set_title(GTK_WINDOW(page->browser->window), page->title.c_str());
}

static void browserUpdateUrl(BrowserPage* page)
{
    gtk_entry_set_text(GTK_ENTRY(page->browser->url_entry), page->url.c_str());
    gtk_widget_set_sensitive(page->browser->back_button, page->can_back);
    gtk_widget_set_sensitive(page->browser->forward_button, page->can_forward);
}

static void browserUpdateAll(BrowserPage* page)
{
    browserUpdateTitle(page);
    browserUpdateUrl(page);
}

static MB_CALL_TYPE void webviewTitleChangeCallback(mbWebView webView, void* param, const utf8* title)
{
    BrowserPage* page = (BrowserPage*)param;
    browserPageSetTitle(page, title);
    if (browserPageIsCurrent(page)) {
        browserUpdateTitle(page);
    }

    HistoryRecord record;
    record.url = page->url;
    record.title = page->title;

    if (page->history_id) {
        record.id = *page->history_id;
        HistoryStorage::getInstance().updateRecord(record);
    } else {
        HistoryStorage::getInstance().saveRecord(record);
        page->history_id.emplace(record.id);
    }
}

static MB_CALL_TYPE void webviewUrlChangeCallback(mbWebView webView, void* param, const utf8* url, BOOL canGoBack,
    BOOL canGoForward)
{
    BrowserPage* page = (BrowserPage*)param;
    browserPageSetUrl(page, url, canGoBack, canGoForward);
    if (browserPageIsCurrent(page)) {
        browserUpdateUrl(page);
    }

    HistoryRecord record;
    record.url = page->url;
    record.title = page->title;
    HistoryStorage::getInstance().saveRecord(record);
    page->history_id.emplace(record.id);
}

static BrowserPage* browserPageCreate(Browser* browser);

static MB_CALL_TYPE mbWebView webviewCreateViewCallback(mbWebView webView, void* param, mbNavigationType navigationType,
    const utf8* url, const mbWindowFeatures* windowFeatures)
{
    BrowserPage* page = (BrowserPage*)param;
    BrowserPage* new_page = browserPageCreate(page->browser);
    return new_page->webview;
}

BOOL onClose(BrowserPage* page)
{
    Browser* browser = page->browser;
    // 1. delete webview
    mbDestroyWebView(page->webview);
    // 2. remove from notebook
    guint n = gtk_notebook_page_num(GTK_NOTEBOOK(page->browser->page_notebook), page->body);
    gtk_notebook_remove_page(GTK_NOTEBOOK(page->browser->page_notebook), n);
    // 3. delete pointer and remove from page_list
    delete page;
    browser->page_list.erase(browser->page_list.begin() + n);
    if (browser->page_list.empty()) {
        gtk_window_close(GTK_WINDOW(browser->window));
        mbExitMessageLoop();
        //g_application_quit(G_APPLICATION(g_browser->app));
    }

    return FALSE;
}

static gboolean browserPageClosePressCallback(GtkWidget* self, GdkEventButton* event, BrowserPage* page)
{
    return onClose(page);
}

BOOL MB_CALL_TYPE onCloseCallback(mbWebView webView, void* param, void* unuse)
{
    printf("onCloseCallback\n");
    onClose((BrowserPage*)param);
    return TRUE;
}

struct DownInfo {
    std::string url;
    size_t recvSize;
    size_t allSize;
};

void MB_CALL_TYPE onNetJobDataRecvCallback(void* ptr, mbNetJob job, const char* data, int length)
{
    DownInfo* info = (DownInfo*)ptr;
    info->recvSize += length;
    printf("onNetJobDataRecvCallback: %d %d, %f\n", info->allSize, info->recvSize, info->recvSize / (info->allSize + 1.0));
}

void MB_CALL_TYPE onNetJobDataFinishCallback(void* ptr, mbNetJob job, mbLoadingResult result)
{
    DownInfo* info = (DownInfo*)ptr;
    std::string url = info->url;

    printf("download ok: %d\n", info->recvSize);
}

static uint8_t get_utf8_bytes(uint8_t utf8)
{
    for (uint8_t i = 0; i < 6; i++) {
        if ((utf8 & (0x80 >> i)) == 0) {
            return i == 0 ? 1 : i;
        }
    }

    return 1;
}

static uint16_t utf8_to_utf16(uint8_t* in, uint16_t inLen, uint16_t* out, uint16_t outLen)
{
    uint16_t length = 0;
    uint8_t bytes = 0;

    for (uint16_t i = 0; i < inLen && length < outLen; i++, length++) {
        bytes = get_utf8_bytes(in[i]);

        if (bytes > 1) {
            out[length] = in[i] & (0xFF >> (bytes + 1));
            for (uint8_t j = 1; j < bytes; j++) {
                i++;
                out[length] <<= 6;
                out[length] += in[i] & 0x3F;
            }
        } else {
            out[length] = in[i];
        }
    }

    out[length] = 0;
    return length;
}

std::string concatModulePath(const std::string& name)
{
    const int kPathLen = 400;
    char* pathUtf8 = (char*)malloc(kPathLen);
    memset(pathUtf8, 0, kPathLen);
    readlink("/proc/self/exe", pathUtf8, kPathLen - 1);

    int lenOfPathUtf8 = (int)strlen(pathUtf8);
    for (int i = lenOfPathUtf8 - 1; i >= 1; --i) {
        if (pathUtf8[i] == '/') {
            pathUtf8[i] = '\0';
            lenOfPathUtf8 = i;
            break;
        }
    }

    std::string ret = pathUtf8;
    free(pathUtf8);

    ret += "/";
    ret += name;
    return ret;
}

static mbDownloadOpt MB_CALL_TYPE onDownloadTest(mbWebView webView,
    void* param,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind) {
    printf("onDownloadCallback: %d %s, %p\n", expectedContentLength, url, mbDownloadByPath);

    DownInfo* info = new DownInfo();
    info->url = url;
    info->recvSize = 0;
    info->allSize = expectedContentLength;

    mbDownloadBind bind = { 0 };
    bind.param = info;
    bind.recvCallback = onNetJobDataRecvCallback;
    bind.finishCallback = onNetJobDataFinishCallback;
    bind.saveNameCallback = nullptr;

    const int kPathLen = 400;
    uint8_t* pathUtf8 = (uint8_t*)malloc(kPathLen);
    memset(pathUtf8, 0, kPathLen);
    int ret = readlink("/proc/self/exe", (char*)pathUtf8, kPathLen - 1);

    int lenOfPathUtf8 = (int)strlen((const char*)pathUtf8);
    for (int i = lenOfPathUtf8 - 1; i >= 1; --i) {
        if (pathUtf8[i] == '/') {
            pathUtf8[i] = '\0';
            lenOfPathUtf8 = i;
            break;
        }
    }

    const int kPathUtf16Len = kPathLen * 2 * 4;
    uint16_t* pathUtf16 = (uint16_t*)malloc(kPathUtf16Len);
    memset(pathUtf16, 0, kPathUtf16Len);
    utf8_to_utf16((uint8_t*)pathUtf8, lenOfPathUtf8, pathUtf16, kPathUtf16Len/2 - 1);

    //return mbPopupDialogAndDownload(webView, nullptr, expectedContentLength, url, mime, disposition, job, dataBind, &bind);
    mbDownloadOpt opt = mbDownloadByPath(webView, nullptr, /*u"//home/weolar/test/livi-browser-gtk/build/downloadfile/"*/
        (const WCHAR*)pathUtf16, expectedContentLength, url, mime, disposition, job, dataBind, &bind);
    
    free(pathUtf16);
    free(pathUtf8);
    return opt;
}

static BrowserPage* browserPageCreate(Browser* browser)
{
    int w, h, n;
    BrowserPage* page = new BrowserPage;
    page->title = "No title";

    browser->page_list.push_back(page);
    page->browser = browser;
    page->tab = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_size_request(page->tab, TAB_WIDTH, 0);
    page->tab_title = gtk_label_new("");
    gtk_label_set_ellipsize(GTK_LABEL(page->tab_title), PANGO_ELLIPSIZE_END);
    page->tab_close = gtk_button_new_with_label("X");

    g_signal_connect(page->tab_close, "button-press-event", G_CALLBACK(browserPageClosePressCallback), page);
    gtk_box_pack_start(GTK_BOX(page->tab), page->tab_title, FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(page->tab), page->tab_close, FALSE, FALSE, 0);

    const bool kOpenglDraw = true;
    void* drawingArea = nullptr;
    if (!kOpenglDraw) {
        page->body = gtk_drawing_area_new(); // !!!
        drawingArea = page->body;
    } else {
        GtkWidget* glArea = (GtkWidget*)gtk_gl_area_new();
        drawingArea = glArea;
#if 0
        GtkWidget* box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
        g_object_set(box, "margin", 2, NULL);
        gtk_box_set_spacing(GTK_BOX(box), 2);
        gtk_box_pack_start(GTK_BOX(box), glArea, TRUE, TRUE, 0);
        page->body = box;
#else
        page->body = glArea;
#endif
    }

    w = gtk_widget_get_allocated_width(page->body);
    h = gtk_widget_get_allocated_height(page->body);

    page->webview = mbCreateWebViewBindGtkWindow(browser->window, drawingArea, kOpenglDraw ? "glArea" : "", 0, 0, w, h);
    //page->webview = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);
    ::mbShowWindow(page->webview, TRUE);
    //::mbLoadURL(page->webview, "https://qq.com/");
    ::mbOnTitleChanged(page->webview, webviewTitleChangeCallback, page);
    ::mbOnURLChanged(page->webview, webviewUrlChangeCallback, page);
    ::mbOnCreateView(page->webview, webviewCreateViewCallback, page);
    ::mbOnClose(page->webview, onCloseCallback, page);
//     mbOnDownloadInBlinkThread(page->webview, onDownloadTest, nullptr);
    //downloadManagerWebviewRegister(page->webview);

    n = gtk_notebook_append_page(GTK_NOTEBOOK(browser->page_notebook), page->body, page->tab);

    gtk_widget_show(page->body);
    gtk_widget_show_all(page->tab);

    browserPageSetTitle(page, "New Page");
    gtk_notebook_set_current_page(GTK_NOTEBOOK(browser->page_notebook), n);
    return page;
}

static void browserPageCreateLoad(Browser* browser, const char* url)
{
    BrowserPage* page = browserPageCreate(browser);
    mbLoadURL(page->webview, url);
}

static gboolean browserDownloadListButtonPressCallback(GtkWidget* self, GdkEventButton* event, Browser* browser)
{
    downloadWindowShow(browser->download_window);
    return FALSE;
}

static gboolean browserNewPageButtonPressCallback(GtkWidget* self, GdkEventButton* event, Browser* browser)
{
    browserPageCreateLoad(browser, browser_home_page);
    return FALSE;
}

static gboolean browserDevtoolsButtonPressCallback(GtkWidget* self, GdkEventButton* event, Browser* browser)
{
    std::string path = concatModulePath("devtools/inspector.html");
    BrowserPage* page = browserCurrentPage(browser);
    mbSetDebugConfig(page->webview, "showDevTools", path.c_str());
    return FALSE;
}

static gboolean browserBackPressCallback(GtkWidget* self, GdkEventButton* event, Browser* browser)
{
    BrowserPage* page = browserCurrentPage(browser);
    mbGoBack(page->webview);
    return FALSE;
}

static gboolean browserForwardPressCallback(GtkWidget* self, GdkEventButton* event, Browser* browser)
{
    BrowserPage* page = browserCurrentPage(browser);
    mbGoForward(page->webview);
    return FALSE;
}

static gboolean browserReloadPressCallback(GtkWidget* self, GdkEventButton* event, Browser* browser)
{
    BrowserPage* page = browserCurrentPage(browser);
    mbReload(page->webview);
    return FALSE;
}

static void browserUrlEntryActivateCallback(GtkEntry* self, Browser* browser)
{
    BrowserPage* page = browserCurrentPage(browser);
    mbLoadURL(page->webview, gtk_entry_get_text(self));
    gtk_widget_grab_focus(page->browser->page_notebook);
}

Browser* g_browser = nullptr;
static void browserWindowDestroyCallback(GtkWidget* self, Browser* browser)
{
    printf("\n\n");
    printf("THIS IS A WORKAROUND TO AVOID MINIBLINK CANNOT EXIT NORMALLY\n");
    printf("                                                     GOODBYE\n");
    //exit(0);
    mbExitMessageLoop();
    //g_application_quit(G_APPLICATION(g_browser->app));
}

static void browserNotebookSwitchPageCallback(GtkNotebook* self, GtkWidget* page, guint page_num, Browser* browser)
{
    printf("browserNotebookSwitchPageCallback: %d %d\n", browser->page_list.size(), page_num);
    browserUpdateAll(browser->page_list[page_num]);

    for (size_t i = 0; i < browser->page_list.size(); ++i) {
        BrowserPage* page = browser->page_list[i];
        if (i != page_num) {
            //gtk_widget_hide(page->body);
        } else
            gtk_widget_show(page->body);
    }
}

static void browserInit(Browser* browser)
{
    HistoryStorage::getInstance().init();
    DownloadStorage::getInstance().init();

    browser->window = gtk_application_window_new(browser->app);
    gtk_window_set_default_size(GTK_WINDOW(browser->window), DEFAULT_WIDTH, DEFAULT_HEIGHT);
    g_signal_connect(browser->window, "destroy", G_CALLBACK(browserWindowDestroyCallback), browser);

    browser->root_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(browser->window), browser->root_box);

    browser->tool_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_pack_start(GTK_BOX(browser->root_box), browser->tool_box, FALSE, FALSE, 0);

    browser->page_notebook = gtk_notebook_new();
    gtk_notebook_set_scrollable(GTK_NOTEBOOK(browser->page_notebook), TRUE);
    g_signal_connect(browser->page_notebook, "switch-page", G_CALLBACK(browserNotebookSwitchPageCallback), browser);
    gtk_box_pack_start(GTK_BOX(browser->root_box), browser->page_notebook, TRUE, TRUE, 0);

    browser->back_button = gtk_button_new();
    g_signal_connect(browser->back_button, "button-press-event", G_CALLBACK(browserBackPressCallback), browser);
    gtk_button_set_label(GTK_BUTTON(browser->back_button), "Back");
    gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->back_button, FALSE, FALSE, 0);

    browser->forward_button = gtk_button_new();
    g_signal_connect(browser->forward_button, "button-press-event", G_CALLBACK(browserForwardPressCallback), browser);
    gtk_button_set_label(GTK_BUTTON(browser->forward_button), "Forward");
    gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->forward_button, FALSE, FALSE, 0);

    browser->reload_button = gtk_button_new();
    g_signal_connect(browser->reload_button, "button-press-event", G_CALLBACK(browserForwardPressCallback), browser);
    gtk_button_set_label(GTK_BUTTON(browser->reload_button), "Reload");
    gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->reload_button, FALSE, FALSE, 0);

    browser->url_entry = gtk_entry_new();
    g_signal_connect(browser->url_entry, "activate", G_CALLBACK(browserUrlEntryActivateCallback), browser);
    gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->url_entry, TRUE, TRUE, 0);

    browser->new_page_button = gtk_button_new_with_label("NP");
    g_signal_connect(browser->new_page_button, "button-press-event", G_CALLBACK(browserNewPageButtonPressCallback), browser);
    gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->new_page_button, FALSE, FALSE, 0);

    // browser->devtools_button = gtk_button_new_with_label("dev");
    // g_signal_connect(browser->devtools_button, "button-press-event", G_CALLBACK(browserDevtoolsButtonPressCallback), browser);
    // gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->devtools_button, FALSE, FALSE, 0);

    // browser->download_list_button = gtk_button_new_with_label("DL");
    // g_signal_connect(browser->download_list_button, "button-press-event",
    //     G_CALLBACK(browserDownloadListButtonPressCallback), browser);
    // gtk_box_pack_start(GTK_BOX(browser->tool_box), browser->download_list_button, FALSE, FALSE, 0);

    browser->download_window = downloadWindowCreate();
}

static void activate(GtkApplication* self, Browser* browser)
{
    UiThread::getInstance().attach();
    browserInit(browser);
    browserPageCreateLoad(browser, browser_home_page);
    gtk_widget_show_all(browser->window);
    mbRunMessageLoop();
    printf("activate, mbRunMessageLoop end\n");
    g_application_quit(G_APPLICATION(g_browser->app));
}

int main(int argc, char* argv[])
{

    Browser browser_ = {};
    g_browser = &browser_;

    argumentsInit(argc, argv);
    runtimeInfoInit();
    mbInit(NULL, runtimeInfoGet().miniblink_kernel.c_str());
    g_browser->app = gtk_application_new(APPLICATION_ID, G_APPLICATION_FLAGS_NONE);
    g_signal_connect(g_browser->app, "activate", G_CALLBACK(activate), g_browser);
    return g_application_run(G_APPLICATION(g_browser->app), argc, argv);
}

}  // namespace livi

int main(int argc, char* argv[])
{
    return livi::main(argc, argv);

}
