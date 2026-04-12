#include "container.h"
#include <QDebug>

Container::~Container() {
    for (auto i : container_) {
        delete i;
    }
    qDebug() << "delete";
}

void Container::add(Shape* shape) {
    container_.push_back(shape);
}

void Container::removeSelected() {
    container_.remove_if([=](Shape* shape) {
        if (shape->isSelected()) {
            delete shape;
            return true;
        }
        return false;
    });
}

void Container::apply(Command* command, std::list<Command*>& history) {
    auto clone_comand = command->clone();
    //qDebug() << "apply";
    if (!clone_comand->execute(container_)) {
        //qDebug() << "unapply";
        delete clone_comand;
        return;
    }
    history.push_back(clone_comand);
}

void Container::setNewBorder(QRect canvas_border) {
    for (auto i : container_) {
        i->setCanvasBorser(canvas_border);
    }
}
/*
void Container::addInGroup(Group* group) {
    bool added = false;
    for (auto i : container_) {
        if (!i->isSelected()) {
            continue;
        }
        group->addShape(i);
        container_.erase(std::find(container_.begin(), container_.end(), i));
        added = true;
    }
    if (!added) {
        return;
    }
    container_.push_back(group);
    //qDebug() << "chto to dobavil" << container_;
    //qDebug() << "chto to ubral" << container_;
}*/