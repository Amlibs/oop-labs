#pragma once

#include "../shape/shape.h"
#include <vector>
#include <list>

class Container {
 public:
    ~Container();
    void add(Shape*);
    void removeSelected();
    auto begin() {
        return container_.begin();
    }
    auto end() {
        return container_.end();
    }
 private:
    std::list<Shape*> container_;
};