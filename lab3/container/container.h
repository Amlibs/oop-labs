#pragma once

#include "../shape/shape.h"
#include "../commands/movecommand.h"
//#include <vector>
#include <list>

class Container {
 public:
    ~Container();
    void add(Shape*);
    void removeSelected();
    void apply(Command*, std::list<Command*>&);
    auto begin() {
        return container_.begin();
    }
    auto end() {
        return container_.end();
    }
 private:
    std::list<Shape*> container_;
};