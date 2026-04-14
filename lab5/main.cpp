#include "./fruit/fruit.h"
#include "./apple/apple.h"
#include "./mandarin/mandarin.h"

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
    std::cout << "_______приведение типов__________" << '\n';
    Fruit* mandarin = new Mandarin();
    Fruit* fruit_apple = new Apple();
    std::cout << mandarin->classname() << '\n';
    std::cout << fruit_apple->classname() << '\n';
    std::cout << fruit->classname() << '\n';
    //fruit_apple->fallFromTree();
    ((Apple*)fruit_apple)->fallFromTree();
    ((Mandarin*)mandarin)->splashJuice();
    //((Mandarin*)fruit_apple)->splashJuice();
    std::cout << "___________проверка класса___________" << '\n';
    std::cout << (mandarin->classname() == "mandarin") << '\n';
    std::cout << (mandarin->classname() == "fruit") << '\n';
    std::cout << "_________       ___________" << '\n';
    std::cout << mandarin->isA("mandarin") << '\n';
    std::cout << mandarin->isA("fruit") << '\n';
    std::cout << mandarin->isA("apple") << '\n';
    std::cout << "_________       ___________" << '\n';
    std::cout << (dynamic_cast<Apple*>(fruit_apple) != nullptr) << '\n';
    std::cout << (dynamic_cast<Fruit*>(fruit_apple) != nullptr) << '\n';
    std::cout << (dynamic_cast<Mandarin*>(fruit_apple) != nullptr) << '\n';
    std::cout << "_____________________________" << '\n';
    delete fruit;
    delete apple;
    delete mandarin;
    return 0;
}