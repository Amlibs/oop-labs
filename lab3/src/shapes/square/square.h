#pragma once

#include "rectangle.h"

class Square : public Rectangle {
 public:
    Square();
    Square(QPoint pos, QRect canvas_border, int x, QColor color) : Rectangle(pos, canvas_border, x, x, color) {};
};