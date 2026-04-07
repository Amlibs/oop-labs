#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../ellipse/ellipse.h"

class Circle : public Ellipse{
 public:
    Circle();
    Circle(QPoint pos, QRect canvas_border, int r, QColor color) : Ellipse(pos, canvas_border, r, r, color) {};
};