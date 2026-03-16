#include ".\building\building.h"
#include ".\residentialbuilding\resbuild.h"
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

    std::cout << "---------------ResBuilding-------------------" << '\n';
    std::cout << "Создание объекта класс ResBuilding" << '\n';
    ResBuilding* house = new ResBuilding();
    std::cout << "----------------------------------------------" << '\n';

    std::cout << "Вызов delete для buildig" << '\n';
    delete build_dynamic;
    std::cout << "delete для Building вызыван" << '\n';

    std::cout << "--------------ResBuildig------------------" << '\n';
    std::cout << "Вызов delete для ResBuildig" << '\n';
    delete house;
    std::cout << "delete для ResBuilding вызыван" << '\n';
    std::cout << "----------------------------------------------" << '\n';

    return 0;
}