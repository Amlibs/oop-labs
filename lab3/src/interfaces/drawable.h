#pragma once

#include <QPainter>

class Drawable {
 public:
    virtual void draw(QPainter&) = 0;
};