#pragma once

#include <iostream>
#include <string>
class Base {
 public:
    Base() { std::cout << "default constructor base()" << '\n'; };
    Base(Base *obj) { std::cout << "pointer constructor base(*obj)" << '\n'; };
    Base(Base &obj) { std::cout << "reference constructor base(&obj)" << '\n'; };
    ~Base() { std::cout << "destructor base()" << '\n'; };
};