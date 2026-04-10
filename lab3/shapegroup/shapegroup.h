#pragma once

#include <list>
#include <algorithm>

#include "../shape/shape.h"

class Group : public Shape {
 public:
    Group(QRect);
    ~Group();
    bool isSelected() override;
    void setSelect(bool) override;
    void setColor(QColor) override;
    bool hit(QPoint) override;
    void draw(QPainter&) override;
    void resize(int) override;
    void updateShape() override;
    void addShape(Shape*);
    void move(int, int);
 private:
    void setBorderGroup();
    std::list<Shape*> group_;
};

