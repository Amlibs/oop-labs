qt_add_library(ellipse STATIC
    ellipse.cpp
)
target_link_libraries(ellipse PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(ellipse INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})