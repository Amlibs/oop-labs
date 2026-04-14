#pragma once

#include <iostream>

class Fruit {
 public:
    Fruit();
    virtual ~Fruit();
    void nonVirtaulFunc1();
    void nonVirtaulFunc2();
    void nonVirtaulFunc3();
    void nonVirtualFunc4();
    virtual void virtualFunc3();
};