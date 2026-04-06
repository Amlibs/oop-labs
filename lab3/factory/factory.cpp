#include "factory.h"

Factory::Factory(QColor color) : color_(color) {}

Shape* Factory::createShapes(QPoint pos) {
    switch (type_) {
        case ShapeType::Triangle:
            return new Triangle(pos, 50, color_);
        case ShapeType::Ellipse:
            return new Ellipse(pos, 70, 35, color_);
        case ShapeType::Circle:
            return new Circle(pos, 50, color_);
        case ShapeType::Rectangle:
            return new Rectangle(pos, 60, 35, color_);
        case ShapeType::Square:
            return new Square(pos, 50, color_);
        default:
            break;
    }
    return nullptr;
}