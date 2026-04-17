#include "./base/base.h"
#include "./desc/desc.h"

#include "testobject.h"

#include <memory>

void func1(Base obj) {
    std::cout << "execute func1" << '\n';
    //(Desc)obj;
}
void func2(Base *obj) {
    std::cout << "execute func2" << '\n';
    //(Desc*)obj;
}
void func3(Base &obj) {
    std::cout << "execute func3" << '\n';
    //(Desc&)obj; 
}

Base func1() { 
    std::cout << "execute base func1" << '\n';
    Base b;
    return b;
}
Base* func2() { 
    std::cout << "execute base func2" << '\n';
    Base b;
    return &b;
}
Base& func3() {
    std::cout << "execute base func3" << '\n';
    Base b;
    std::cout << &b << '\n';
    return b;
}
Base func4() { 
    std::cout << "execute base func4" << '\n';
    return new Base();
}
Base* func5() {
    std::cout << "execute base func5" << '\n';
    return new Base();
}
Base& func6() { 
    std::cout << "execute base func6" << '\n';
    return *(new Base());
}

std::unique_ptr<TestObject> smart_func1() {
    std::cout << "execute base smart_func1" << '\n';
    return std::make_unique<TestObject>();
}

std::unique_ptr<TestObject> smart_func2(std::unique_ptr<TestObject> p) {
    std::cout << "execute base smart_func2" << '\n';
    p->print();
    return p;
}

Base smart_func3() {
    std::cout << "execute base smart_func3" << '\n';
    auto p = std::make_unique<Base>();
    return *p;
}

std::shared_ptr<TestObject2> smart_func4() {
    std::cout << "execute base smart_func4" << '\n';
    return std::make_shared<TestObject2>();
}

std::shared_ptr<TestObject2> smart_func5(std::shared_ptr<TestObject2> p) {
    std::cout << "execute base smart_func5" << '\n';
    p->print();
    return p;
}

Base smart_func6() {
    std::cout << "execute base smart_func6" << '\n';
    auto p = std::make_shared<Base>();
    return *p;
}


int main() {
    Base b;
    Desc d;
    std::cout << "------------------" << '\n';
    func1(b);
    std::cout << "------------------" << '\n';
    func2(&b);
    std::cout << "------------------" << '\n';
    func3(b);
    std::cout << "__________________" << '\n';
    func1(d);
    std::cout << "------------------" << '\n';
    func2(&d);
    std::cout << "------------------" << '\n';
    func3(d);
    std::cout << "____6 функций_____" << '\n';
    std::cout << "--------func1----------" << '\n';
    Base base = func1();
    //Base temp = base;
    std::cout << "--------func2----------" << '\n';
    Base* pbase = func2();
    std::cout << (pbase == nullptr) << '\n';
    std::cout << "--------func3----------" << '\n';
    Base& rbase = func3();
    std::cout << &rbase << '\n';
    std::cout << "--------func4----------" << '\n';
    Base base_2 = func4();
    std::cout << "--------func5----------" << '\n';
    Base* pbase_2 = func5();
    delete pbase_2;
    std::cout << "--------func6----------" << '\n';
    Base& rbase_2 = func6();
    delete &rbase_2;
    std::cout << "___________unique_ptr____________" << '\n';

    std::unique_ptr<TestObject> ptr = smart_func1();
    ptr = smart_func2(std::move(ptr));
    Base u = smart_func3();
    std::cout << "___________shared_ptr____________" << '\n';
    std::shared_ptr<TestObject2> ptr_2 = smart_func4();
    ptr_2 = smart_func5(std::move(ptr_2));
    Base s = smart_func6();
    std::cout << "_______________________" << '\n';
    return 0;
}
