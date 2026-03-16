#include ".\building\build.h"
#include <iostream>

int main() {
    Build* build_dynamic = new Build();

    std::cout << build_dynamic->getHeight() << '\n';
    build_dynamic->setHeight(50);
    std::cout << build_dynamic->getHeight() << '\n';
    std::cout << build_dynamic->getWidth() << '\n';
    build_dynamic->setWidth(10);
    std::cout << build_dynamic->getWidth() << '\n';

    Build build(*build_dynamic);

    Build param_building(5, 10);

    delete build_dynamic;
}