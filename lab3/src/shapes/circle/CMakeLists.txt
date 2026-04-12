qt_add_library(circle STATIC
    circle.h
)
target_link_libraries(circle PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(circle INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})