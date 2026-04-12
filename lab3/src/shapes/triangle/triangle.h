#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include <QPolygon>
#include "shape.h"

class Triangle : public Shape{
 public:
    Triangle();
    Triangle(QPoint, QRect, double, QColor);
    void setLength(int a) {
        length_ = a;
    }
    void setHeight(double h) {
        height_ = h;
    }
    bool hit(const QPoint) override;
    void draw(QPainter&) override;
    void updateShape() override;
    void resize(int) override;
    bool isPositiveLenght() override;
 protected:
    double length_;
    double height_;
    QPoint a_;
    QPoint b_;
    QPoint c_;
    QPolygon polygon;
};