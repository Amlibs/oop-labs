#include "resbuild.h"
#include <iostream>

ResBuilding::ResBuilding(): room_count_(0), have_sewerage_(true) {
    std::cout << "Простой конструктор у ResBuilding" << '\n';
}

ResBuilding::ResBuilding(int room_count, bool have_sewerage): room_count_(room_count), have_sewerage_(have_sewerage) {
    std::cout << "Конструктор с параметрами ResBuilding" << '\n';
}

ResBuilding::ResBuilding(ResBuilding& house) {
    std::cout << "Конструктор копирования ResBuilding" << '\n';
    have_sewerage_ = house.have_sewerage_;
    room_count_ = house.room_count_;
}

ResBuilding::~ResBuilding() {
    std::cout << "Деструктор ResBuilding" << '\n';
}
