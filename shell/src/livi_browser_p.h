#ifndef __livi_browser_h__
#define __livi_browser_h__

#include <gtk/gtk.h>
#include <mb.h>

#include <vector>

#include "livi_download_storage.h"
#include "livi_download_window.h"
#include "livi_history_storage.h"

namespace livi {

static const char *APPLICATION_ID = "com.iscas.isrc.livi.browser";
static const guint DEFAULT_WIDTH = 1024;
static const guint DEFAULT_HEIGHT = 768;
static const guint TAB_WIDTH = 200;
static const guint TAB_TITLE_CHAR_MAX = 24;

struct Browser;

struct BrowserPage {
    Browser *browser;
    GtkWidget *tab;
    GtkWidget *tab_title;
    GtkWidget *tab_close;
    GtkWidget *body;
    mbWebView webview;
    std::string title;
    std::string url;
    bool can_forward;
    bool can_back;
    std::optional<uint64_t> history_id;
};

struct Browser {
    GtkApplication *app;
    GtkWidget *window;
    GtkWidget *root_box;
    GtkWidget *tool_box;
    GtkWidget *page_notebook;

    GtkWidget *back_button;
    GtkWidget *forward_button;
    GtkWidget *reload_button;
    GtkWidget *url_entry;
    GtkWidget *new_page_button;
    GtkWidget *download_list_button;
    GtkWidget *devtools_button;

    std::vector<BrowserPage *> page_list;

    DownloadWindow *download_window;
};
}  // namespace livi

#endif
