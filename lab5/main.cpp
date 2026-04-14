#include "./fruit/fruit.h"
#include "./apple/apple.h"

int main() {
    Fruit* fruit = new Fruit();
    Apple* apple = new Apple();
    std::cout << "------вызов невиртуального метода в род.классе-------" << '\n';
    apple->nonVirtaulFunc2();
    std::cout << "------вызов виртуального метода в род.классе-------" << '\n';
    apple->nonVirtaulFunc3();
    std::cout << "Вызов невиртуального метода через указатель на класс предка и потомка" << '\n';
    Fruit* temp_fruit = new Apple();
    Apple* temp_apple = new Apple();
    temp_fruit->nonVirtualFunc4();
    temp_apple->nonVirtualFunc4();
    delete temp_fruit;
    delete temp_apple;
    std::cout << "Вызов виртуального метода через указатель на класс предка и потомка" << '\n';
    temp_fruit = new Apple();
    temp_apple = new Apple();
    temp_fruit->virtualFunc3();
    temp_apple->virtualFunc3();
    delete temp_fruit;
    delete temp_apple;
    delete fruit;
    delete apple;
    return 0;
}