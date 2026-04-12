qt_add_library(commands STATIC
    movecommand.cpp
    resizecommand.cpp
    changecolorcommand.cpp
    deletecommand.cpp
    createcommand.cpp
    groupcommand.cpp
    ungroupcommand.cpp
)

target_link_libraries(commands PUBLIC Qt6::Core shape_core shape_group)
target_include_directories(commands PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})