#include "groupcommand.h"

GroupCommand::GroupCommand(std::list<Shape*>& container, Group* group) : container_ (container), group_(group) {}

bool GroupCommand::execute(std::list<Shape*>& shapes) {
    bool added = false;
    for (auto it = container_.begin(); it != container_.end(); it++) {
        Shape* i = *it;
        if (!i->isSelected()) {
            continue;
        }
        //qDebug() << "add group" << i << '\n';
        group_->addShape(i);
        container_.erase(it);
        added = true;
    }
    if (!added) {
        return false;
    }
    //qDebug() << group_ << '\n';
    container_.push_back(group_);
    return true;
}

void GroupCommand::unexecute() {
    auto result = group_->returnAndClear();
    for (auto i : result) {
        container_.push_back(i);
    }
    container_.erase(std::find(container_.begin(), container_.end(), group_));
    delete group_;
}

Command* GroupCommand::clone() {
    return new GroupCommand(container_, group_);
}