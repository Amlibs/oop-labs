#pragma once

#include <QString>

#include "factory.h"
#include "shapetype.h"
#include "shape.h"

class ShapeLoaderFromFile {
 public:
    ShapeLoaderFromFile(){};
    ~ShapeLoaderFromFile(){};
    Shape* loadShape(QTextStream&, Factory*);
 private:
    ShapeType convertStringTypeToEnum(QString);
};