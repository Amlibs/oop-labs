qt_add_library(square STATIC
    square.cpp
)
target_link_libraries(square PRIVATE Qt6::Core)
target_include_directories(square INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})