#pragma once

#include <QPoint>
#include <QPainter>

class Shape {
 public:
    Shape() : center_(QPoint(0, 0)), select_(0) {};
    Shape(QPoint center, bool select) : center_(center), select_(select) {};
    bool isSelected() {
        return select_;
    }
    void setSelect(bool select) {
        select_ = select;
    }
    void setCenter(QPoint point) {
        center_ = point;
    }
    virtual void draw(QPainter&) = 0;
    virtual bool hit(QPoint const) = 0;
 protected:
    QPoint center_;
    bool select_;
};