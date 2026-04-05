#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../shape/shape.h"

class Circle : public Shape{
 public:
    Circle();
    Circle(QPoint, int);
    bool isSelected() override {
        return select_;
    }
    void setSelect(bool select) override {
        select_ = select;
    }
    void setCenter(QPoint point) {
        center_ = point;
    }
    void setRadius(int r) {
        radius_ = r;
    }
    bool hit(QPoint const) override;
    void draw(QPainter&) override;
 private:
    int radius_;
};