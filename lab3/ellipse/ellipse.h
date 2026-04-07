#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../shape/shape.h"

class Ellipse : public Shape{
 public:
    Ellipse();
    Ellipse(QPoint, int, int, QColor);
    void setRadiusX(int rx) {
        radius_x_ = rx;
    }
    void serRadiusY(int ry) {
        radius_y_ = ry;
    }
    bool hit(const QPoint) override;
    void draw(QPainter&) override;
    void updateShape() override;
    void resize(int) override;
    QRect getBorders() override {
        return borders_;
    }
 protected:
    int radius_x_;
    int radius_y_;
    QRect borders_;
};