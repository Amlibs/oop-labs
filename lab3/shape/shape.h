#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>

class Shape {
 public:
    Shape() : center_(QPoint(0, 0)), select_(false), color_(QColor::fromRgb(153, 255, 204)) {};
    Shape(QPoint center, bool select, QColor color = QColor::fromRgb(153, 255, 204)) : center_(center), select_(select), color_(color) {};
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
            painter.setBrush(QBrush(color_, Qt::SolidPattern));
            painter.setPen(QColor::fromRgb(0, 204, 102));
            //qDebug() << "Hello rect";
        } else {
            painter.setBrush(QBrush(color_, Qt::SolidPattern));
            painter.setPen(QColor::fromRgb(0, 0, 204));
            //qDebug() << "Hello ctrl rect";
        }
    }
    virtual bool hit(QPoint const) = 0;
    void move(int dx, int dy) {
        //qDebug() << "shape move" << dx << dy;
        center_ = QPoint(center_.x() + dx, center_.y() + dy);
    }
    virtual void updateShape() = 0;
    virtual QRect getBorders() = 0;
    virtual void resize(int) = 0;

    void print() {
        qDebug() << "tri" << getBorders();
    }

 protected:
    QPoint center_;
    bool select_;
    QColor color_;
};