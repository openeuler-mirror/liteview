#ifndef __livi_download_window_h__
#define __livi_download_window_h__

#include <gtk/gtk.h>
#include <stdint.h>

#include <memory>
#include <string>
#include <vector>

namespace livi {

struct DownloadWindow;

struct DownloadItem {
    uint64_t id;
    GtkWidget *root;
    GtkWidget *filename;
    GtkWidget *progressbar;
    GtkWidget *pause_button;
    GtkWidget *resume_button;
    GtkWidget *cancel_button;
    GtkWidget *delete_button;
    GtkWidget *open_in_folder_button;

    struct DownloadWindow *download_window;
};

struct DownloadWindow {
    GtkWidget *window;
    GtkWidget *root;
    std::vector<std::unique_ptr<DownloadItem>> items;
};

DownloadWindow *downloadWindowCreate();
void downloadWindowShow(DownloadWindow *download_window);
void downloadWindowHide(DownloadWindow *download_window);

}  // namespace livi

#endif
