#pragma once

#include "../circle/circle.h"
#include <vector>
#include <list>

class Container {
 public:
    void addCircle(const Circle&);
    void removeSelected();
    auto begin() {
        return container_.begin();
    }
    auto end() {
        return container_.end();
    }
 private:
    std::list<Circle> container_;
};