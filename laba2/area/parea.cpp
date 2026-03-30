#include <iostream>
#include "..\residentialbuilding\resbuild.h"
#include "..\building\building.h"

class PArea {
 private:
    Building* house_;
 public:
    PArea (int width, int length, int height) {
        std::cout << "Конструктор с параметрами для Pointer Area" <<'\n';
        house_ = new ResBuilding(width, length, height);
    }

    PArea () {
        std::cout << "Простой конструктор PArea" << '\n';
        house_ = new ResBuilding();
    }

    PArea (const PArea& house) {
        std::cout << "Конструктор копирования PArea" << '\n';
        house_ = new Building(*house.house_);
    }

    ~PArea() {
        std::cout << "Деструктор для Pointer Area" << '\n';
        delete house_;
    }

    void printInfo() {
        std::cout << house_->getWidth() << ' ' << house_->getLength() << ' ' << house_->getHeight() << '\n';
    }
};