#include "container.h"

void Container::addCircle(const Circle& circle) {
    container_.push_back(circle);
}

void Container::removeSelected() {
    container_.remove_if([](Circle& circle) {return circle.isSelected();});
}