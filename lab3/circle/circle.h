#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../shape/shape.h"

class Circle : public Shape{
 public:
    Circle();
    Circle(QPoint, int);
    void setRadius(int r) {
        radius_ = r;
    }
    bool hit(QPoint const) override;
    void draw(QPainter&) override;
 private:
    int radius_;
};