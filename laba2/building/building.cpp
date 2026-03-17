#include "building.h"
#include <iostream>

Building::Building(): width_(0), height_(0), length_(0) {
    std::cout << "Простой конструктор у класса Building вызван" << '\n';   
}

Building::Building(int width, int length, int height): width_(width), length_(length), height_(height) {
    std::cout << "Параметризированный конструктор класса Building" << '\n';
}

Building::Building(const Building& building) {
    std::cout << "Конструктор копирования класса Building" << '\n';
    width_ = building.width_;
    height_ = building.height_;
    length_ = building.length_;
}

int Building::getHeight() {
    std::cout << "Building:: Вернул высоту" << '\n';
    return height_;
}

int Building::getWidth() {
    std::cout << "Building:: Вернул ширину" << '\n';
    return width_;
}


int Building::getLength() {
    std::cout << "Building:: Вернул длину" << '\n';
    return length_;
}

void Building::setHeight (int x) {
    std::cout << "Building:: Установаил высоту" << '\n';
    height_ = x;
}

void Building::setWidth(int x) {
    std::cout << "Building:: Установаил ширину" << '\n';
    width_ = x;
}

void Building::setLength(int x) {
    std::cout << "Building:: Установаил длину" << '\n';
    length_ = x;
}

int Building::getSquare() {
    return width_ * length_;
}

Building::~Building() {
    std::cout << "Деструктор класса Building" << '\n';
}
