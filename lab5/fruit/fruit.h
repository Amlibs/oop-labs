#pragma once

#include <iostream>
#include <string>

class Fruit {
 public:
    Fruit();
    virtual ~Fruit();
    void nonVirtaulFunc1();
    void nonVirtaulFunc2();
    void nonVirtaulFunc3();
    void nonVirtualFunc4();
    virtual void virtualFunc3();
    virtual std::string classname() {
        return "fruit";
    }
    virtual bool isA(std::string name) {
        return name == "fruit";
    }
};