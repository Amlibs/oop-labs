#pragma once

#include <QPoint>
#include <QPainter>
#include <QDebug>

class Shape {
 public:
    Shape() : center_(QPoint(0, 0)), select_(false), color_(QColor::fromRgb(153, 255, 204)) {};
    Shape(QPoint center, QRect canvas_border, bool select, QColor color = QColor::fromRgb(153, 255, 204)) : center_(center), select_(select), canvas_border_(canvas_border), color_(color) {};
    virtual ~Shape() {}
    virtual bool isSelected() {
        return select_;
    }
    virtual void setSelect(bool select) {
        select_ = select;
    }
    void setCenter(QPoint point) {
        center_ = point;
    }
    virtual void setColor(QColor color) {
        color_ = color;
    }
    void setCanvasBorser(QRect canvas_border) {
        canvas_border_ = canvas_border;
        returnInCanvas();
    }
    QColor getColor() {
        return color_;
    }
    QRect getBorder() {
        return border_;
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
    virtual void move(int dx, int dy) {
        //qDebug() << "shape move" << dx << dy;
        center_ = QPoint(center_.x() + dx, center_.y() + dy);
    }
    virtual void updateShape() = 0;
    virtual void resize(int) = 0;

    void print() {
        qDebug() << "tri" << getBorder();
    }

    bool isValid() {
        qDebug() << canvas_border_.contains(border_) << border_ << canvas_border_;
        return canvas_border_.contains(border_);
    }

    void returnInCanvas() {
        int dx = 0;
        int dy = 0;

        if (border_.x() < 0) {
            dx = - border_.x();
        }
        if (border_.y() < 0) {
            dy = - border_.y();
        }

        if (border_.x() + border_.width() > canvas_border_.x() + canvas_border_.width()) {
            //qDebug() << border_.x() + border_.width() << canvas_border_.x() + canvas_border_.width() << (border_.x() + border_.width()) - (canvas_border_.x() + canvas_border_.width());
            dx = (canvas_border_.x() + canvas_border_.width()) - (border_.x() + border_.width());
        }
        if (border_.y() + border_.height() > canvas_border_.y() + canvas_border_.height()) {
            dy = (canvas_border_.y() + canvas_border_.height()) - (border_.y() + border_.height());
        }
        //qDebug() << "asdasdasda" << dx << dy << border_.x() << border_.y();
        //qDebug() << center_;
        move(dx, dy);
        updateShape();
        //qDebug() << center_;
    }

 protected:
    QPoint center_;
    bool select_;
    QColor color_;
    QRect canvas_border_;
    QRect border_;
};