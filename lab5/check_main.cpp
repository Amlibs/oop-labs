#include "./base/base.h"
#include "./desc/desc.h"

void func1(Base obj) {
    std::cout << "execute func1" << '\n';
    //(Desc)obj;
}
void func2(Base *obj) {
    std::cout << "execute func1" << '\n';
    //(Desc*)obj;
}
void func3(Base &obj) {
    std::cout << "execute func1" << '\n';
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
    std::cout << "--------func4----------" << '\n';
    Base base_2 = func4();
    std::cout << "--------func5----------" << '\n';
    Base* pbase_2 = func5();
    delete pbase_2;
    std::cout << "--------func6----------" << '\n';
    Base& rbase_2 = func6();
    delete &rbase_2;
    std::cout << "-----------------------" << '\n';
    return 0;
}
