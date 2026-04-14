#include "fruit.h"

Fruit::Fruit() {
    std::cout << "constructor Fruit()" << '\n';
}

Fruit::~Fruit() {
    std::cout << "destructor Fruit()" << '\n';
}

void Fruit::nonVirtaulFunc1() {
    std::cout << "Fruit: nonVirtaulFunc1" << '\n';
    nonVirtaulFunc2();
}

void Fruit::nonVirtaulFunc2() {
    std::cout << "Fruit: nonVirtaulFunc2" << '\n';
}

void Fruit::nonVirtaulFunc3() {
    std::cout << "Fruit: nonVirtaulFunc3" << '\n';
    virtualFunc3();
}

void Fruit::nonVirtualFunc4() {
    std::cout << "Fruit: nonVirtualFunc4" << '\n';
}

void Fruit::virtualFunc3() {
    std::cout << "Fruit: virtualFunc3" << '\n';
}