#pragma once

#include "../shape/shape.h"
#include "../commands/movecommand.h"
#include "../shapegroup/shapegroup.h"
//#include <vector>
#include <list>

class Container {
 public:
    ~Container();
    void add(Shape*);
    void removeSelected();
    void apply(Command*, std::list<Command*>&);
    void setNewBorder(QRect);
    void addInGroup(Group*);
    auto begin() {
        return container_.begin();
    }
    auto end() {
        return container_.end();
    }
    std::list<Shape*>& getList() {
        return container_;
    }
 private:
    std::list<Shape*> container_;
};