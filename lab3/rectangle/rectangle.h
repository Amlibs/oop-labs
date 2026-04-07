#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>
#include "../shape/shape.h"

class Rectangle : public Shape {
 public:
    Rectangle();
    Rectangle(QPoint, int, int, QColor);
    void setWidth(int w) {
        height_ = w;
    }
    void setLength(int l) {
        length_ = l;
    }
    bool hit(const QPoint) override;
    void draw(QPainter&) override;
    void updateShape() override;
    void resize(int) override;
    QRect getBorders() override {
        return borders_;
    }
 protected:
    int height_;
    int length_;
    int x_;
    int y_;
    QRect borders_;
};