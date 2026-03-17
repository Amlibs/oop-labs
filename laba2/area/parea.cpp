#include <iostream>
#include "..\residentialbuilding\resbuild.h"
#include "..\building\building.h"

class PArea {
 private:
    Building* house_;
 public:
    PArea (int width, int length, int height) {
        house_ = new ResBuilding(width, length, height);
    }

    ~PArea() {
        delete house_;
    }

    void printInfo() {
        std::cout << house_->getWidth() << ' ' << house_->getLength() << ' ' << house_->getHeight() << '\n';
    }
};