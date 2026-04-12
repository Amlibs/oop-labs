#pragma once

#include "rectangle.h"

class Square : public Rectangle {
 public:
    Square() {};
    Square(QPoint pos, QRect canvas_border, int x, QColor color) : Rectangle(pos, canvas_border, x, x, color) {};
    void save(QTextStream& stream) override {
        QString temp = QString("%1 %2").arg(length_).arg(color_.name());
        stream << getDataForFile() << ' ' << temp << '\n';
    }
    void load(QStringList& line) override {
        Shape::load(line);
        length_ = line[7].toInt();
        updateShape();
    }
    QString type() override { return "square"; }
};