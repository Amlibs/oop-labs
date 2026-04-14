#include "apple.h"

Apple::Apple() {
    std::cout << "constructor Apple()" << '\n';
}

Apple::~Apple() {
    std::cout << "destructor Apple()" << '\n';
}

void Apple::nonVirtaulFunc2() {
    std::cout << "Apple: nonVirtaulFunc2" << '\n';
    nonVirtaulFunc1();
}

void Apple::nonVirtaulFunc3() {
    std::cout << "Apple: nonVirtaulFunc3" << '\n';
    Fruit::nonVirtaulFunc3();
}

void Apple::nonVirtualFunc4() {
    std::cout << "Apple: nonVirtualFunc4" << '\n';
}

void Apple::virtualFunc3() {
    std::cout << "Apple: virtualFunc3" << '\n';
}