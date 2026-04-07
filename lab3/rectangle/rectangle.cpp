#include "rectangle.h"

Rectangle::Rectangle() {
    height_ = 50;
    length_ = 70;
    x_ = 0;
    y_ = 0;
}

Rectangle::Rectangle(QPoint pos, int l, int h, QColor color) : Shape(pos, false, color), height_(h), length_(l) {
    x_ = pos.x() - l / 2;
    y_ = pos.y() - h / 2;
    borders_ = QRect(x_, y_, length_, height_);
}


void Rectangle::draw(QPainter& painter) {
    Shape::draw(painter);
    painter.drawRect(x_, y_, length_, height_);
}

bool Rectangle::hit(const QPoint pos) {
    if (x_ > pos.x() || x_ + length_ < pos.x()) {
        return false;
    }
    if (y_ > pos.y() || y_ + height_ < pos.y()) {
        return false;
    }
    return true;
}

void Rectangle::updateShape() {
    x_ = center_.x() - length_ / 2;
    y_ = center_.y() - height_ / 2;
    borders_ = QRect(x_, y_, length_, height_);
}

void Rectangle::resize(int dx) {
    height_ += dx;
    length_ += dx;
}


