#include "build.h"
#include <iostream>

Build::Build(): width_(0), height_(0) {
    std::cout << "Простой конструктор у класса Build вызван" << '\n';   
}

Build::Build(int width, int height): width_(width), height_(height) {
    std::cout << "Параметризированный конструктов класса Build" << '\n';
}

Build::Build(Build& build) {
    std::cout << "Конструктор копирования класса Build" << '\n';
    width_ = build.width_;
    height_ = build.height_;
}

int Build::getHeight() {
    std::cout << "Build:: Вернул высоту" << '\n';
    return height_;
}

int Build::getWidth() {
    std::cout << "Build:: Вернул ширину" << '\n';
    return width_;
}


void Build::setHeight (int x) {
    std::cout << "Build:: Установаил высоту" << '\n';
    height_ = x;
}

void Build::setWidth(int x) {
    std::cout << "Build:: Установаил ширину" << '\n';
    width_ = x;
}

Build::~Build() {
    std::cout << "Деструктор класса Build" << '\n';
}
