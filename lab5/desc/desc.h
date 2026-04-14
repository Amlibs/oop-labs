#pragma once

#include "../base/base.h"

class Desc : public Base {
 public:
    Desc() { std::cout << "default constructor desc()" << '\n'; };
    Desc(Desc *obj) { std::cout << "pointer constructor desc(*obj)" << '\n'; };
    Desc(Desc &obj) { std::cout << "reference constructor desc(&obj)" << '\n'; };
    ~Desc() { std::cout << "destructor desc()" << '\n'; };
};