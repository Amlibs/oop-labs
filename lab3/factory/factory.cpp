#include "factory.h"

Factory::Factory(QColor color) : color_(color) {}

Shape* Factory::createShapes(QPoint pos, QRect canvas_border) {
    switch (type_) {
        case ShapeType::Triangle:
            return new Triangle(pos, canvas_border, 50, color_);
        case ShapeType::Ellipse:
            return new Ellipse(pos, canvas_border, 70, 35, color_);
        case ShapeType::Circle:
            return new Circle(pos, canvas_border, 50, color_);
        case ShapeType::Rectangle:
            return new Rectangle(pos, canvas_border, 60, 35, color_);
        case ShapeType::Square:
            return new Square(pos, canvas_border, 50, color_);
        default:
            break;
    }
    return nullptr;
}