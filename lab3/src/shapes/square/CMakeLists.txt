qt_add_library(square STATIC
    square.cpp
)
target_link_libraries(square PUBLIC Qt6::Core Qt6::Gui shape_core)
target_include_directories(square INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})