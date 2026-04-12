qt_add_library(rectangle STATIC
    rectangle.cpp
)
target_link_libraries(rectangle PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(rectangle INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})