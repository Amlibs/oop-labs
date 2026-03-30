#include ".\building\building.h"
#include ".\residentialbuilding\resbuild.h"
#include ".\area\area.cpp"
#include ".\area\parea.cpp"
#include <iostream>

int main() {
    std::cout << "---------------Building-------------------" << '\n';
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
    std::cout << build.getWidth() << ' ' << build.getLength() << ' ' << build.getHeight() << ' ' << '\n';
    std::cout << "Изменим высоту скопированного объекта" << '\n';
    build.setHeight(999);
    std::cout << build.getHeight() << '\n';
    std::cout << "Проверим поменялось ли значение у изначального объекта" << '\n';
    std::cout << build_dynamic->getWidth() << ' ' << build_dynamic->getLength() << ' ' << build_dynamic->getHeight() << '\n';

    std::cout << "Теперь возьмем объект по указателю" << '\n';
    Building* building_2 = build_dynamic;
    std::cout << "Поменяем значение по указателю" << '\n';
    building_2->setWidth(99990);
    std::cout << building_2->getWidth() << '\n';
    std::cout << "Проверим поменялось ли значение у изначального объекта" << '\n';
    std::cout << build_dynamic->getWidth() << ' ' << build_dynamic->getLength() << ' ' << build_dynamic->getHeight() << '\n';

    Building param_building(5, 5, 10);
    std::cout << "----------------------------------------------" << '\n';

    std::cout << "---------------ResBuilding-------------------" << '\n';
    std::cout << "Создание объекта класс ResBuilding" << '\n';
    ResBuilding* house = new ResBuilding();
    std::cout << "Вызываем getlength у ResBuilding" << '\n';
    std::cout << house->getLength() << '\n';
    //std::cout << "Создаем объект класса ResBuilding, используя конструктор с параметрами" << '\n';
    ResBuilding* big_house = new ResBuilding(4, true);
    std::cout << "Вызываем getlength у нового объекта ResBuilding" << '\n';
    std::cout << big_house->getLength() << '\n';
    ResBuilding* house_2 = new ResBuilding(10, 10, 10);
    std::cout << "Вызываем getlength у нового объекта ResBuilding" << '\n';
    std::cout << house_2->getLength() << '\n';
    std::cout << "Вызываем getSquare у нового объекта ResBuilding" << '\n';
    std::cout << house_2->getSquare() << '\n';
    std::cout << "----------------------------------------------" << '\n';

    std::cout << "-------------------Area--------------------" << '\n';
    Area* area = new Area(10, true);
    area->printInfo();
    std::cout << "Создание Area с помощью конструктора компирования" << '\n';
    Area* area_2 = area;
    std::cout << "Создание Area с помощью базового конструктора" << '\n';
    Area* area_3 = new Area();
    std::cout << "Вызов delete для area" << '\n';
    delete area;
    delete area_2;
    delete area_3;
    std::cout << "delete для area вызыван" << '\n';
    std::cout << "----------------------------------------------" << '\n';

    std::cout << "---------------PointerArea--------------------" << '\n';
    PArea* parea = new PArea(100, 100, 110);
    parea->printInfo();
    std::cout << "Вызов конструктора копирования PArea" << '\n';
    PArea* parea_2 = new PArea(*parea);
    std::cout << "Вызов базового конструктора" << '\n';
    PArea* parea_3 = new PArea();
    std::cout << "Вызов delete для parea" << '\n';
    delete parea;
    delete parea_2;
    delete parea_3;
    std::cout << "delete для parea вызыван" << '\n';
    std::cout << "----------------------------------------------" << '\n';

    std::cout << "Вызов delete для buildig" << '\n';
    delete build_dynamic;
    std::cout << "delete для Building вызыван" << '\n';

    std::cout << "--------------ResBuildig------------------" << '\n';
    std::cout << "Вызов delete для ResBuildig" << '\n';
    delete house;
    delete house_2;
    std::cout << "delete для ResBuilding вызыван" << '\n';
    std::cout << "----------------------------------------------" << '\n';

    return 0;
}