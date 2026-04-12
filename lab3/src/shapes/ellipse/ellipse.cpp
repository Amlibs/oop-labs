#include "ellipse.h"

Ellipse::Ellipse() {};

Ellipse::Ellipse(QPoint pos, QRect canvas_border, int rx, int ry, QColor color) : Shape(pos, canvas_border, false, color), radius_x_(rx), radius_y_(ry) {
    border_ = QRect(pos.x() - rx, pos.y() - ry, 2 * rx, 2 * ry);
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
    border_ = QRect(center_.x() - radius_x_, center_.y() - radius_y_, 2 * radius_x_, 2 * radius_y_);
}

void Ellipse::resize(int dx) {
    radius_x_ += dx;
    radius_y_ += dx;
    qDebug() << radius_x_ << radius_y_;
}

bool Ellipse::isPositiveLenght() {
    return radius_x_ > 0 && radius_y_ > 0;
}

void Ellipse::save(QTextStream& stream) {
    QString temp = QString("%1 %2 %3").arg(radius_x_).arg(radius_y_).arg(color_.name());
    stream << getDataForFile() << ' ' << temp << '\n';
}

void Ellipse::load(QStringList& line) {
    Shape::load(line);
    radius_x_ = line[7].toDouble();
    radius_y_ = line[8].toDouble();
    updateShape();
}

QString Ellipse::type() {
    return "ellipse";
}
