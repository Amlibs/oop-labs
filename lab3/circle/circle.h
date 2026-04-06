#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../ellipse/ellipse.h"

class Circle : public Ellipse{
 public:
    Circle();
    Circle(QPoint pos, int r, QColor color) : Ellipse(pos, r, r, color) {};
};