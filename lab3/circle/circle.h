#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>

class Circle {
 public:
    Circle();
    Circle(QPoint, int);
    bool isSelected(){
        return select_;
    }
    void setSelect(bool select) {
        select_ = select;
    }
    void setCenter(QPoint point) {
        center_ = point;
    }
    void setRadius(int r) {
        radius_ = r;
    }
    bool hitInCircle(QPoint const);
    void drawCircle(QPainter&);
 private:
    QPoint center_;
    int radius_;
    bool select_;
};