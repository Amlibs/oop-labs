cmake_minimum_required(VERSION 3.21)
project(testqt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

qt_standard_project_setup()

qt_add_executable(testqt
    main.cpp
    myButton.cpp
    myButton.h
    myWidget.h
    myWidget.cpp
)

target_link_libraries(testqt PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)


set_target_properties(testqt PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)