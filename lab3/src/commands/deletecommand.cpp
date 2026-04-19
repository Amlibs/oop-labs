#include "deletecommand.h"

DeleteCommand::DeleteCommand(std::list<Shape*>& container) : container_ (container) {
}

bool DeleteCommand::execute(std::list<Shape*>& shapes) {
    bool flag = false;
    for (auto i = shapes.begin(); i != shapes.end(); i++) {
        Shape* shape = *i;
        if (!shape->isSelected()) {
            continue;
        }
        flag = true;
        shapes_.push_back(shape);
        shapes.erase(i);
    }
    return flag;
}

void DeleteCommand::unexecute() {
    for (auto i = shapes_.begin(); i != shapes_.end(); i++) {
        Shape* shape = *i;
        container_.push_back(shape);
    }
    shapes_.clear();
}

Command* DeleteCommand::clone() {
    return new DeleteCommand(container_);
}