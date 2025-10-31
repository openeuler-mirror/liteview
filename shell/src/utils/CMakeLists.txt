add_library(livi_utils STATIC 
    guess.cpp
    taskqueue.cpp
    arguments.cpp
    runtime_info.cpp
    process.cpp
)
target_link_libraries(livi_utils PRIVATE fmt::fmt-header-only)
