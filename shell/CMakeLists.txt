cmake_minimum_required(VERSION 3.5)

project(LiteView LANGUAGES CXX)

# 使用 C++11，与 .pro 中保持一致
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成的可执行文件放到当前工程目录下的 bin 目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Qt 自动处理 moc / ui
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 5.7 REQUIRED COMPONENTS Core Widgets Gui Network)

# 显式编译资源；若宏不可用则退回由 AUTORCC 处理 .qrc
if(COMMAND qt5_add_resources)
    qt5_add_resources(SETTINGS_RCC src/res.qrc)
else()
    set(SETTINGS_RCC src/res.qrc)
endif()

set(SOURCES
    src/main.cpp
    src/mb_core.cpp
    src/widget.cpp
    src/webwidget.cpp
    src/webtabbar.cpp
    src/faviconcache.cpp
)

set(HEADERS
    src/faviconcache.h
    src/widget.h
    src/webwidget.h
    src/webtabbar.h
    src/browsersettingswidget.h
    src/browserhistorystore.h
    src/addressinputhistorystore.h
    src/mb.h
)

set(UIS
    src/widget.ui
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    ${SETTINGS_RCC}
)

# 工程根目录 images/ 存在时，构建后复制到可执行文件同目录，便于导航栏加载图标
if(EXISTS "${CMAKE_SOURCE_DIR}/images")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/images"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/images"
        COMMENT "Copy images/ next to executable")
endif()

# 源码、.ui、.qrc 均在 src/
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}
)
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.16")
    set_property(TARGET ${PROJECT_NAME} PROPERTY AUTOUIC_SEARCH_PATHS
        "${CMAKE_CURRENT_SOURCE_DIR}/src")
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE user32 gdi32)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE dl)
endif()
