qt_add_library(circle STATIC
    circle.h
)
target_link_libraries(circle PRIVATE Qt6::Core)
target_include_directories(circle INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})