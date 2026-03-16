#include ".\building\building.h"
#include <iostream>

int main() {
    Building* build_dynamic = new Building();

    std::cout << build_dynamic->getHeight() << '\n';
    build_dynamic->setHeight(50);
    std::cout << build_dynamic->getHeight() << '\n';
    std::cout << build_dynamic->getWidth() << '\n';
    build_dynamic->setWidth(10);
    std::cout << build_dynamic->getWidth() << '\n';
    std::cout << build_dynamic->getLength() << '\n';
    build_dynamic->setLength(20);
    std::cout << build_dynamic->getLength() << '\n';

    Building build(*build_dynamic);

    Building param_building(5, 5, 10);

    std::cout << "Вызов delete для buildig" << '\n';
    delete build_dynamic;
    std::cout << "delete вызыван" << '\n';
    return 0;
}