#pragma once

#include "../rectangle/rectangle.h"

class Square : public Rectangle {
 public:
    Square();
    Square(QPoint pos, int x, QColor color) : Rectangle(pos, x, x, color) {};
};