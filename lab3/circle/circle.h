#pragma once

#include <QPoint>
#include <QPainter>

class Circle {
 public:
    Circle();
    Circle(QPoint, int);
    bool isSelected(){
        return select_;
    }
    bool hitInCircle(QPoint const);
    void drawCircle(QPainter&);
 private:
    QPoint center_;
    int radius_;
    bool select_;
};