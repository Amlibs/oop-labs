#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../shape/shape.h"

class Rectangle : public Shape {
 public:
    Rectangle();
    Rectangle(QPoint, int, int);
    bool isSelected() override {
        return select_;
    }
    void setSelect(bool select) override {
        select_ = select;
    }
    void setCenter(QPoint point) {
        center_ = point;
    }
    void setWidth(int w) {
        height_ = w;
    }
    void setLength(int l) {
        length_ = l;
    }
    bool hit(const QPoint) override;
    void draw(QPainter&) override;
 protected:
    int height_;
    int length_;
    int x_;
    int y_;
};