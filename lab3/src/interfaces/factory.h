#pragma once

#include <QColor>
#include <QPoint>
#include "shape.h"
#include "shapetype.h"

class Factory {
 public:
    Factory() {};
    virtual ~Factory() {};
    virtual Shape* createShapes(ShapeType, QPoint, QRect, QColor) = 0;
};