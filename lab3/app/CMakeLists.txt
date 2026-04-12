qt_add_executable(main
    main.cpp
    ./canvas/canvas.h
    ./canvas/canvas.cpp
    ./container/container.h
    ./container/container.cpp
    ./factory/factory.h
    ./factory/factory.cpp
    shapetype.h
)

target_link_libraries(main PUBLIC Qt6::Widgets Qt6::Core Qt6::Gui shape_core circle ellipse triangle rectangle square commands)


set_target_properties(main PROPERTIES
    WIN32_EXECUTABLE OFF
)