qt_add_library(triangle STATIC
    triangle.cpp
)
target_link_libraries(triangle PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(triangle INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})