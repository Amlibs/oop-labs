#pragma once

#include "../fruit/fruit.h"

class Apple : public Fruit {
 public:
    Apple();
    ~Apple();
    void nonVirtaulFunc2();
    void nonVirtaulFunc3();
    void nonVirtualFunc4();
    void virtualFunc3() override;
    void fallFromTree() {
        std::cout << "apple fall" << '\n';
    }
    std::string classname() override {
        return "apple";
    }
    bool isA(std::string name) {
        return name == "apple" || Fruit::isA(name);
    }
};