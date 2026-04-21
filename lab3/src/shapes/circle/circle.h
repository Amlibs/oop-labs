#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../ellipse/ellipse.h"

class Circle : public Ellipse{
 public:
    Circle() {};
    Circle(QPoint pos, QRect canvas_border, int r, QColor color) : Ellipse(pos, canvas_border, r, r, color) {};
    void save(QTextStream& stream) override {
        QString temp = QString("%1 %2").arg(radius_x_).arg(color_.name());
        stream << getDataForFile() << ' ' << temp << '\n';
    }
    void load(QStringList& line, QTextStream& stream, Factory* factory, ShapeLoaderFromFile* loader) override {
        Shape::load(line, stream, factory, loader);
        radius_x_ = line[7].toDouble();
        radius_y_ = radius_x_;
        updateShape();
    }
    QString type() override { return "circle"; }
};