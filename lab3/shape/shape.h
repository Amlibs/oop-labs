#pragma once

#include <QPoint>
#include <QPainter>

class Shape {
 public:
    Shape() : center_(QPoint(0, 0)), select_(false) {};
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
    virtual void draw(QPainter& painter) {
        painter.setRenderHint(QPainter::Antialiasing);
        //qDebug() << select_;
        if (!select_) {
            painter.setBrush(QBrush(QColor::fromRgb(153, 255, 204), Qt::SolidPattern));
            painter.setPen(QColor::fromRgb(0, 204, 102));
            //qDebug() << "Hello rect";
        } else {
            painter.setBrush(QBrush(QColor::fromRgb(153, 255, 204), Qt::SolidPattern));
            painter.setPen(QColor::fromRgb(0, 0, 204));
            //qDebug() << "Hello ctrl rect";
        }
    }
    virtual bool hit(QPoint const) = 0;
 protected:
    QPoint center_;
    bool select_;
};