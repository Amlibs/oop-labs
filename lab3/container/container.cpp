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

void Container::apply(Command* command, std::list<Command*>& history) {
    for (auto i : container_) {
        if (!i->isSelected()) {
            continue;
        }
        auto clone_comand = command->clone();
        if (!clone_comand->execute(i)) {
            delete clone_comand;
            continue;
        }
        history.push_back(clone_comand);
        //i->print();
        //qDebug() << "exec";
    }
} 