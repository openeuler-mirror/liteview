find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(ICU REQUIRED icu-i18n)
find_package(Libev REQUIRED)

add_subdirectory(utils)

add_executable(livi-browser-gtk
    livi_browser.cpp
    livi_download_manager.cpp
    livi_download_window.cpp
    livi_download_impl_curl.cpp
    livi_download_storage.cpp
    livi_history_storage.cpp
    livi_ui_thread.cpp
    livi_work_thread.cpp
)

set_target_properties(livi-browser-gtk PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_compile_options(livi-browser-gtk  -Wall -Wextra)
target_include_directories(livi-browser-gtk PRIVATE ${GTK3_INCLUDE_DIRS})
target_include_directories(livi-browser-gtk PRIVATE ${ICU_INCLUDE_DIRS})
target_include_directories(livi-browser-gtk PRIVATE ../third_party/miniblink)
target_link_libraries(livi-browser-gtk PRIVATE livi_utils)
target_link_libraries(livi-browser-gtk PRIVATE fmt::fmt-header-only sqlite_orm::sqlite_orm libcurl)
target_link_libraries(livi-browser-gtk PRIVATE dl pthread)
target_link_libraries(livi-browser-gtk PRIVATE ${GTK3_LIBRARIES})
target_link_libraries(livi-browser-gtk PRIVATE ${ICU_LIBRARIES})
target_link_libraries(livi-browser-gtk PRIVATE ${LIBEV_LIBRARIES})
