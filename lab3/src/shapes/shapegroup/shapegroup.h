#pragma once

#include <list>
#include <algorithm>

#include "shape.h"
#include "../../app/loader/loaderfromfile.h"

class Group : public Shape {
 public:
    Group(QRect);
    ~Group();
    bool isSelected() override;
    void setSelect(bool) override;
    void setColor(QColor) override;
    void setCenterGroup();
    bool hit(QPoint) override;
    void draw(QPainter&) override;
    void resize(int) override;
    bool isPositiveLenght() override;
    void updateShape() override;
    void addShape(Shape*);
    std::list<Shape*> returnAndClear();
    void move(int, int, std::unordered_set<Shape*>&) override;
    void save(QTextStream&) override;
    void load(QStringList&, QTextStream&, Factory*, ShapeLoaderFromFile*) override;
    QTreeWidgetItem* getWidgetItem() override;
    QString type() override;
    bool isGroup() override {
        return true;
    }
 private:
    void setBorderGroup();
    std::list<Shape*> group_;
};

