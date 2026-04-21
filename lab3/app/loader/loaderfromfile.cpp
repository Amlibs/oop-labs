#include "loaderfromfile.h"


Shape* ShapeLoaderFromFile::loadShape(QTextStream& stream, Factory* factory) {
    QString data = stream.readLine();
    QStringList line = data.trimmed().split(' '); 
    qDebug() << (line[0] == "triangle");

    ShapeType type = convertStringTypeToEnum(line[0]);
    Shape* shape = factory->createShapes(type, QPoint(), QRect(), QColor());
    shape->load(line, stream, factory, this);
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