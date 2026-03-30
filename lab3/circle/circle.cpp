#include "circle.h"
#include <QPoint>
#include <QPainter>

Circle::Circle() {
    center_ = QPoint(0, 0);
    radius_ = 20;
    select_ = false;
}

Circle::Circle(QPoint point, int radius) : center_(point), radius_(radius), select_(false) {
}

bool Circle::hitInCircle(const QPoint pos) {
    int x = pos.x() - center_.x();
    int y = pos.y() - center_.y();
    if ((x * x + y * y) < (radius_ * radius_)) {
        return true;
    }
    return false;
}

void Circle::drawCircle(QPainter& painter) {
    painter.setRenderHint(QPainter::Antialiasing);
    //qDebug() << select_;
    if (!select_) {
        painter.setBrush(QBrush(QColor::fromRgb(153, 255, 204), Qt::SolidPattern));
        painter.setPen(QColor::fromRgb(0, 204, 102));
        //qDebug() << "Hello";
    } else {
        painter.setBrush(QBrush(QColor::fromRgb(153, 255, 204), Qt::SolidPattern));
        painter.setPen(QColor::fromRgb(0, 0, 204));
        //qDebug() << "Hello5454544548";
    }
    painter.drawEllipse(center_, radius_, radius_);
}