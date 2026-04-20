qt_add_library(arrowlink STATIC
    arrowlink.cpp
)
target_link_libraries(arrowlink PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(arrowlink INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})