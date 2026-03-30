cmake_minimum_required(VERSION 3.21)
project(qtlab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

qt_standard_project_setup()

qt_add_executable(qtlab3
    main.cpp
    ./canvas/canvas.h
    ./canvas/canvas.cpp
    ./circle/circle.h
    ./circle/circle.cpp
)

target_link_libraries(qtlab3 PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)


set_target_properties(qtlab3 PROPERTIES
    WIN32_EXECUTABLE ON
)