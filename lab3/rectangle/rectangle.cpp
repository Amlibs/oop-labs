#include "rectangle.h"

Rectangle::Rectangle() {
    height_ = 50;
    length_ = 70;
    x_ = 0;
    y_ = 0;
}

Rectangle::Rectangle(QPoint pos, int l, int h) : Shape(pos, false), height_(h), length_(l) {
    x_ = pos.x() - l / 2;
    y_ = pos.y() - h / 2;
}


void Rectangle::draw(QPainter& painter) {
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


