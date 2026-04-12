cmake_minimum_required(VERSION 3.21)
project(qtlab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

qt_standard_project_setup()

add_subdirectory(app)
add_subdirectory(src/commands)
add_subdirectory(src/interfaces)
add_subdirectory(src/shapes/triangle)
add_subdirectory(src/shapes/rectangle)
add_subdirectory(src/shapes/square)
add_subdirectory(src/shapes/ellipse)
add_subdirectory(src/shapes/circle)
add_subdirectory(src/shapes/shapegroup)  