#pragma once

#include "../rectangle/rectangle.h"

class Square : public Rectangle {
 public:
    Square();
    Square(QPoint pos, int x) : Rectangle(pos, x, x) {};
};