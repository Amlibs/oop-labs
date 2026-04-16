#include "loaderfromfile.h"


Shape* ShapeLoaderFromFile::loadShape(QTextStream& stream, Factory* factory) {
    QString data = stream.readLine();
    QStringList line = data.trimmed().split(' '); 
    qDebug() << (line[0] == "triangle");

    ShapeType type = convertStringTypeToEnum(line[0]);
    Shape* shape = factory->createShapes(type, QPoint(), QRect(), QColor());
    shape->load(line);
    if (dynamic_cast<Group*>(shape) != nullptr) {
        Group* gshape = dynamic_cast<Group*>(shape);
        for (int j = 0; j < line[1].toInt(); j++) {
            gshape->addShape(loadShape(stream, factory));
        }
        return gshape;
    }
    return shape;
}

ShapeType ShapeLoaderFromFile::convertStringTypeToEnum(QString string) {
    if (string == "triangle") return ShapeType::Triangle;
    if (string == "ellipse") return ShapeType::Ellipse;
    if (string == "circle") return ShapeType::Circle;
    if (string == "rectangle") return ShapeType::Rectangle;
    if (string == "square") return ShapeType::Square;
    return ShapeType::Group;
}