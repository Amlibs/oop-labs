#include "container.h"
#include <QDebug>

Container::~Container() {
    for (auto i : container_) {
        delete i;
    }
    //qDebug() << "delete";
}

void Container::addCircle(Circle* circle) {
    container_.push_back(circle);
}

void Container::removeSelected() {
    container_.remove_if([](Circle* circle) {return circle->isSelected();});
}