#pragma once

#include "factory.h"

#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "triangle.h"
#include "shapegroup.h"

class FactoryShape : public Factory {
 public:
    FactoryShape();
    ~FactoryShape();
    Shape* createShapes(ShapeType, QPoint, QRect, QColor) override;
};