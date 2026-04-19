qt_add_executable(main
    main.cpp
    ./canvas/canvas.h
    ./canvas/canvas.cpp
    ./canvas/mousetype.h
    ./factories/factoryshape.cpp
    ./factories/factoryshape.h
    ./container/container.h
    ./container/container.cpp
    ./loader/loaderfromfile.h
    ./loader/loaderfromfile.cpp
    ./treeshapeview/treeshapeview.h
    ./treeshapeview/treeshapeview.cpp
)

target_link_libraries(main PUBLIC Qt6::Widgets Qt6::Core Qt6::Gui shape_core circle ellipse triangle rectangle square commands)


set_target_properties(main PROPERTIES
    WIN32_EXECUTABLE OFF
)