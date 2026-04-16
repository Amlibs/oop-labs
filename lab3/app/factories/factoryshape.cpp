#include "factoryshape.h"

FactoryShape::FactoryShape() {}

Shape* FactoryShape::createShapes(ShapeType type, QPoint pos, QRect canvas_border, QColor color) {
    switch (type) {
        case ShapeType::Triangle:
            return new Triangle(pos, canvas_border, 50, color);
        case ShapeType::Ellipse:
            return new Ellipse(pos, canvas_border, 70, 35, color);
        case ShapeType::Circle:
            return new Circle(pos, canvas_border, 50, color);
        case ShapeType::Rectangle:
            return new Rectangle(pos, canvas_border, 60, 35, color);
        case ShapeType::Square:
            return new Square(pos, canvas_border, 50, color);
        case ShapeType::Group:
            return new Group(canvas_border);
        default:
            break;
    }
    return nullptr;
}

FactoryShape::~FactoryShape() {

}