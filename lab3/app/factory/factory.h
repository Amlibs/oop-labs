#pragma once

#include <QColor>
#include <QPoint>
#include "circle.h"
#include "../container/container.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "triangle.h"
#include "../shapetype.h"

class Factory {
 public:
    Factory(QColor);
    Shape* createShapes(QPoint, QRect);
    void setColor(QColor color) {
        color_ = color;
    }
    void setType(ShapeType type) {
        type_ = type; 
    }
 private:
    QColor color_;
    ShapeType type_ = ShapeType::Triangle;
};