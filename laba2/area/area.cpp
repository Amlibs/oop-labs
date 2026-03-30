#include <iostream>
#include "..\residentialbuilding\resbuild.h"

class Area {
 private:
    ResBuilding house_;
 public:
    Area (int room, bool sewerage) : house_(room, sewerage) {
        std::cout << "Конструктор с параметрами класса Area" << '\n';
    }

    Area () : house_() {
        std::cout << "Базовый конструктор класса Area" << '\n';
    }

    Area(const Area& house) : house_(house.house_) {
        std::cout << "Конструктор копирования класса Area" << '\n';
    }

    ~Area() {
        std::cout << "Деструктор класса Area" << '\n';
    }

    void printInfo() {
        std::cout << house_.getRoomCount() << ' ' << house_.isSewerage() << '\n';
    }
};