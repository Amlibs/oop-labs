#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../ellipse/ellipse.h"

class Circle : public Ellipse{
 public:
    Circle();
    Circle(QPoint pos, int r) : Ellipse(pos, r, r) {};
};