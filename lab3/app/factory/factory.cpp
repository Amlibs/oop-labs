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

Shape* Factory::createShapesFromFile(QTextStream& stream) {
    QString data = stream.readLine();
    QStringList line = data.trimmed().split(' '); 
    qDebug() << (line[0] == "triangle");
    Shape* shape = nullptr;
    if (line[0] == "triangle") {
        shape = new Triangle();
        shape->load(line);
        qDebug() << line;
        return shape;
    }
    if (line[0] == "ellipse") {
        shape = new Ellipse();
        shape->load(line);
        return shape;
    }
    if (line[0] == "circle") {
        shape = new Circle();
        shape->load(line);
        return shape;
    }
    if (line[0] == "rectangle") {
        shape = new Rectangle();
        shape->load(line);
        return shape;
    }
    if (line[0] == "square") {
        shape = new Square();
        shape->load(line);
        return shape;
    }
    if (line[0] == "group") {
        Group* gshape = new Group(QRect(0, 0, line[2].toInt(), line[3].toInt()));
        for (int j = 0; j < line[1].toInt(); j++) {
            gshape->addShape(createShapesFromFile(stream));
        }
        return gshape;
    }
    return nullptr;
}