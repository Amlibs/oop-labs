#pragma once

#include <list>
#include <algorithm>

#include "shape.h"

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
    bool isPositiveLenght() override;
    void updateShape() override;
    void addShape(Shape*);
    std::list<Shape*> returnAndClear();
    void move(int, int) override;
    void save(QTextStream&) override;
    void load(QStringList&) override;
    QTreeWidgetItem* getWidgetItem() override;
    QString type() override;
    bool isGroup() override {
        return true;
    }
 private:
    void setBorderGroup();
    std::list<Shape*> group_;
};

