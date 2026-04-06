#pragma once

#include <QColor>
#include <QPoint>
#include "../circle/circle.h"
#include "../container/container.h"
#include "../rectangle/rectangle.h"
#include "../square/square.h"
#include "../ellipse/ellipse.h"
#include "../triangle/triangle.h"
#include "../shapetype.h"

class Factory {
 public:
    Factory(QColor);
    Shape* createShapes(QPoint);
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