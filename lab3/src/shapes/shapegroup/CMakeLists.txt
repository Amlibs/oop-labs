qt_add_library(shape_group STATIC
    shapegroup.cpp
)
target_link_libraries(shape_group PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(shape_group INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})