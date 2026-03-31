cmake_minimum_required(VERSION 3.21)
project(qtlab32 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

qt_standard_project_setup()

qt_add_executable(qtlab32
    main.cpp
    ./model/model.h
    ./model/model.cpp
    ./view/view.h
    ./view/view.cpp
)

target_link_libraries(qtlab32 PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)


set_target_properties(qtlab32 PROPERTIES
    WIN32_EXECUTABLE OFF
)