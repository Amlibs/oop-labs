#include "triangle.h"
#include <cmath>

Triangle::Triangle(QPoint pos, double a, QColor color) : Shape(pos, false, color), length_(a) {
    //qDebug() << a_ << center_;
    height_ = a * std::sqrt(3) / 2;
    a_ = QPoint(center_.x(), center_.y() - 2 * height_ / 3);
    b_ = QPoint(center_.x() - length_ / 2, center_.y() + height_ / 3);
    c_ = QPoint(center_.x() + length_ / 2, center_.y() + height_ / 3);
    polygon << a_ << b_ << c_ ;
    borders_ = QRect(QPoint(b_.x(), b_.y() - height_), QSize((int)length_, (int)height_));
    //qDebug() << height_;
}

void Triangle::draw(QPainter& painter) {
    Shape::draw(painter);
    //qDebug() << polygon;
    painter.drawPolygon(polygon);
}

bool Triangle::hit(const QPoint pos) {
    //qDebug() << polygon.containsPoint(pos, Qt::OddEvenFill);
    return polygon.containsPoint(pos, Qt::OddEvenFill);
}

void Triangle::updateShape() {
    a_ = QPoint(center_.x(), center_.y() - 2 * height_ / 3);
    b_ = QPoint(center_.x() - length_ / 2, center_.y() + height_ / 3);
    c_ = QPoint(center_.x() + length_ / 2, center_.y() + height_ / 3);
    //qDebug() << polygon;
    polygon.clear();
    polygon << a_ << b_ << c_ ;
    borders_ = QRect(QPoint(b_.x(), b_.y() - height_), QSize((int)length_, (int)height_));
    //qDebug() << polygon; 
}