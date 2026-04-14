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
};