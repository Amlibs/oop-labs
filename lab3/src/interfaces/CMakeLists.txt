qt_add_library(shape_core STATIC
    command.h
    shape.h
)
target_link_libraries(shape_core PUBLIC Qt6::Core Qt6::Gui)
target_include_directories(shape_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})