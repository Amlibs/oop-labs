#include "ellipse.h"

Ellipse::Ellipse() {};

Ellipse::Ellipse(QPoint pos, int rx, int ry, QColor color) : Shape(pos, false, color), radius_x_(rx), radius_y_(ry) {
    borders_ = QRect(pos.x() - rx, pos.y() - ry, 2 * rx, 2 * ry);
}

bool Ellipse::hit(const QPoint pos) {
    double x = pos.x() - center_.x();
    double y = pos.y() - center_.y();
    double rx = radius_x_;
    double ry = radius_y_;
    if ((x * x) / (rx * rx) + (y * y) / (ry * ry) < 1.0) {
        return true;
    }
    return false;
}

void Ellipse::draw(QPainter& painter) {
    Shape::draw(painter);
    painter.drawEllipse(center_, radius_x_, radius_y_);
}

void Ellipse::updateShape() {
    borders_ = QRect(center_.x() - radius_x_, center_.y() - radius_y_, 2 * radius_x_, 2 * radius_y_);
}

void Ellipse::resize(int dx) {
    radius_x_ += dx;
    radius_y_ += dx;
}
