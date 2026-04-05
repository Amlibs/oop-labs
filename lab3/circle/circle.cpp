#include "circle.h"
#include <QPoint>
#include <QPainter>

Circle::Circle() {
    center_ = QPoint(0, 0);
    radius_ = 20;
    select_ = false;
}

Circle::Circle(QPoint point, int radius) : Shape(point, false), radius_(radius) {
}

bool Circle::hit(const QPoint pos) {
    int x = pos.x() - center_.x();
    int y = pos.y() - center_.y();
    if ((x * x + y * y) < (radius_ * radius_)) {
        return true;
    }
    return false;
}

void Circle::draw(QPainter& painter) {
    Shape::draw(painter);
    painter.drawEllipse(center_, radius_, radius_);
}