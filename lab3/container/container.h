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
    std::list<Shape*>::iterator find(Shape*);
    auto begin() {
        return container_.begin();
    }
    auto end() {
        return container_.end();
    }
    auto rbegin() {
        return container_.rbegin();
    }
    auto rend() {
        return container_.rend();
    }
    std::list<Shape*>& getList() {
        return container_;
    }
    bool haveSelectedGroup() {
        bool have = false;
        for (auto i : container_){
            if (i->isGroup() && i->isSelected()) {
                have = true;
                break;
            }
        }
        return have;
    }
    bool haveSelected() {
        bool have = false;
        for (auto i : container_){
            if (i->isSelected()) {
                have = true;
                break;
            }
        }
        return have;
    }
 private:
    std::list<Shape*> container_;
};