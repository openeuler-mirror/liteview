#include "livi_download_window.h"

#include <assert.h>

#include <algorithm>

#include "livi_download_manager.h"
#include "livi_download_storage.h"
#include "utils/process.h"

namespace livi {

static const guint DEFAULT_WIDTH = 800;
static const guint DEFAULT_HEIGHT = 600;

static DownloadStorage &downloadStorage = DownloadStorage::getInstance();

static void downloadItemUpdate(DownloadItem *item, const DownloadJobInfo &info) {
    gtk_label_set_label(GTK_LABEL(item->filename), info.filename.c_str());
    double total_size = info.total_size ? info.download_size / (double)info.total_size : 0;
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(item->progressbar), total_size);
    const char *str_state;
    bool show_pause = false, show_resume = false, show_cancel = false;

    switch (info.state) {
        case DOWNLOAD_STATE_RUN:
            str_state = "run";
            show_pause = true;
            show_cancel = true;
            break;
        case DOWNLOAD_STATE_DONE:
            str_state = "done";
            break;
        case DOWNLOAD_STATE_PAUSE:
            str_state = "pause";
            show_resume = true;
            show_cancel = true;
            break;
        case DOWNLOAD_STATE_CANCEL:
            str_state = "cancel";
            break;
        case DOWNLOAD_STATE_FAIL:
            str_state = "fail";
            break;
        default:
            str_state = "unknown";
            break;
    }
    if (show_pause) {
        gtk_widget_show(item->pause_button);
    } else {
        gtk_widget_hide(item->pause_button);
    }
    if (show_resume) {
        gtk_widget_show(item->resume_button);
    } else {
        gtk_widget_hide(item->resume_button);
    }

    if (show_cancel) {
        gtk_widget_show(item->cancel_button);
    } else {
        gtk_widget_hide(item->cancel_button);
    }

    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(item->progressbar), str_state);
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(item->progressbar), TRUE);
}

static gboolean downloadItemPausePressCallback(GtkWidget *self, GdkEventButton *event, DownloadItem *item) {
    //downloadManagerJobPause(item->id);
    return FALSE;
}

static gboolean downloadItemResumePressCallback(GtkWidget *self, GdkEventButton *event, DownloadItem *item) {
    //downloadManagerJobResume(item->id);
    return FALSE;
}

static gboolean downloadItemCancelPressCallback(GtkWidget *self, GdkEventButton *event, DownloadItem *item) {
    //downloadManagerJobCancel(item->id);
    return FALSE;
}

static gboolean downloadItemDeletePressCallback(GtkWidget *self, GdkEventButton *event, DownloadItem *item) {
    auto record = downloadStorage.getJobById(item->id);
    if (record.has_value()) {
        remove(record->filepath.c_str());
        downloadStorage.removeJob(record->id);
    }
    auto &items = item->download_window->items;
    auto iter = std::find_if(std::begin(items), std::end(items),
                             [&](std::unique_ptr<DownloadItem> &ptr) { return ptr.get() == item; });
    assert(iter != std::end(items));
    gtk_widget_destroy((*iter)->root);
    items.erase(iter);
    return FALSE;
}

static gboolean downloadItemOpenFolderPressCallback(GtkWidget *self, GdkEventButton *event, DownloadItem *item) {
    auto record = downloadStorage.getJobById(item->id);
    if (record.has_value()) {
        const char *argv[3] = {
            "nautilus",
            record->filepath.c_str(),
            nullptr,
        };
        processStart(argv);
    }
    return FALSE;
}

static DownloadItem *downloadItemCreate(uint64_t id) {
    DownloadItem *result = new DownloadItem;
    result->id = id;
    result->root = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    result->filename = gtk_label_new("filename");
    gtk_box_pack_start(GTK_BOX(result->root), result->filename, FALSE, FALSE, 0);
    result->progressbar = gtk_progress_bar_new();
    gtk_box_pack_start(GTK_BOX(result->root), result->progressbar, TRUE, TRUE, 0);
    result->pause_button = gtk_button_new_with_label("P");
    gtk_box_pack_start(GTK_BOX(result->root), result->pause_button, FALSE, FALSE, 0);
    result->resume_button = gtk_button_new_with_label("R");
    gtk_box_pack_start(GTK_BOX(result->root), result->resume_button, FALSE, FALSE, 0);
    result->cancel_button = gtk_button_new_with_label("C");
    gtk_box_pack_start(GTK_BOX(result->root), result->cancel_button, FALSE, FALSE, 0);
    result->delete_button = gtk_button_new_with_label("D");
    gtk_box_pack_start(GTK_BOX(result->root), result->delete_button, FALSE, FALSE, 0);
    result->open_in_folder_button = gtk_button_new_with_label("O");
    gtk_box_pack_start(GTK_BOX(result->root), result->open_in_folder_button, FALSE, FALSE, 0);

    gtk_widget_show(result->root);
    gtk_widget_show(result->filename);
    gtk_widget_show(result->progressbar);
    gtk_widget_show(result->delete_button);
    gtk_widget_show(result->open_in_folder_button);

    g_signal_connect(result->pause_button, "button-press-event", G_CALLBACK(downloadItemPausePressCallback), result);
    g_signal_connect(result->resume_button, "button-press-event", G_CALLBACK(downloadItemResumePressCallback), result);
    g_signal_connect(result->cancel_button, "button-press-event", G_CALLBACK(downloadItemCancelPressCallback), result);
    g_signal_connect(result->delete_button, "button-press-event", G_CALLBACK(downloadItemDeletePressCallback), result);
    g_signal_connect(result->open_in_folder_button, "button-press-event",
                     G_CALLBACK(downloadItemOpenFolderPressCallback), result);

    return result;
}

static void createCallback(const DownloadJobInfo &job, void *userdata) {
    DownloadWindow *download_window = (DownloadWindow *)userdata;
    DownloadItem *item = downloadItemCreate(job.id);
    item->download_window = download_window;
    download_window->items.emplace_back(item);
    gtk_box_pack_start(GTK_BOX(download_window->root), item->root, FALSE, FALSE, 0);
    downloadItemUpdate(item, job);
}
static void updateCallback(const DownloadJobInfo &job, void *userdata) {
    DownloadWindow *download_window = (DownloadWindow *)userdata;
    auto begin = std::begin(download_window->items);
    auto end = std::end(download_window->items);
    auto iter = std::find_if(begin, end, [&](std::unique_ptr<DownloadItem> &ptr) { return ptr->id == job.id; });
    assert(iter != end);
    downloadItemUpdate(&**iter, job);
}

DownloadWindow *downloadWindowCreate() {
    DownloadWindow *download_window = new DownloadWindow;
    download_window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    download_window->root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(download_window->window), download_window->root);
    gtk_widget_show(download_window->root);
    g_signal_connect(download_window->window, "delete-event", G_CALLBACK(gtk_widget_hide_on_delete), download_window);
    downloadManagerInit(createCallback, updateCallback, download_window);
    return download_window;
}

void downloadWindowShow(DownloadWindow *download_window) {
    gtk_widget_show(download_window->window);
    gtk_window_present(GTK_WINDOW(download_window->window));
}

}  // namespace livi
