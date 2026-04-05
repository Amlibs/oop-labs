#include "container.h"
#include <QDebug>

Container::~Container() {
    for (auto i : container_) {
        delete i;
    }
    //qDebug() << "delete";
}

void Container::add(Shape* shape) {
    container_.push_back(shape);
}

void Container::removeSelected() {
    container_.remove_if([](Shape* shape) {return shape->isSelected();});
}