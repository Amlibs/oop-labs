#pragma once

#include <iostream>

class TestObject {
 public:
    TestObject() {std::cout << "constructor test object" << '\n';};
    ~TestObject() {std::cout << "destructor test object" << '\n';};
    void print() {
        std::cout << "print" << '\n';
    }
};

class TestObject2 {
 public:
    TestObject2() {std::cout << "constructor test object2" << '\n';};
    ~TestObject2() {std::cout << "destructor test object2" << '\n';};
    void print() {
        std::cout << "print testik 2" << '\n';
    }
};