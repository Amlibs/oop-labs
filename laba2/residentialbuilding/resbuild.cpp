#include "resbuild.h"
#include <iostream>

ResBuilding::ResBuilding(): room_count_(0), have_sewerage_(false) {
    std::cout << "Простой конструктор у ResBuilding" << '\n';
}

ResBuilding::ResBuilding(int room_count, bool have_sewerage): room_count_(room_count), have_sewerage_(have_sewerage) {
    std::cout << "Конструктор с параметрами ResBuilding" << '\n';
}

ResBuilding::ResBuilding(int wigth, int length, int heigth): Building(wigth, length, heigth) {
    std::cout << "Конструктор класса ResBuilding с параметрами родительского класса" << '\n';
}

ResBuilding::ResBuilding(int wigth, int length, int heigth, int room_count, bool have_sewerage): Building(wigth, length, heigth),  room_count_(room_count), have_sewerage_(have_sewerage) {
    std::cout << "Конструктор класса ResBuilding с параметрами родительского класса и своими параметрами" << '\n';
}

ResBuilding::ResBuilding(ResBuilding& house) : Building(house) {
    std::cout << "Конструктор копирования ResBuilding" << '\n';
    have_sewerage_ = house.have_sewerage_;
    room_count_ = house.room_count_;
}

ResBuilding::~ResBuilding() {
    std::cout << "Деструктор ResBuilding" << '\n';
}

int ResBuilding::getRoomCount() {
    return room_count_;
}

bool ResBuilding::isSewerage() {
    return have_sewerage_;
}

void ResBuilding::setRoomCount(int room_count) {
    room_count_ = room_count;
}

void ResBuilding::setSewerage(bool have_sewerage) {
    have_sewerage_ = have_sewerage;
}
