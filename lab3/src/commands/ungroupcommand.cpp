#include "ungroupcommand.h"

UnGroupCommand::UnGroupCommand(std::list<Shape*>& container) : container_ (container), group_(nullptr) {}

bool UnGroupCommand::execute(std::list<Shape*>& shapes) {
    Group* group = nullptr;
    std::list<Shape*> result;
    for (auto i : container_) {
        if (!i->isGroup()) continue;

        if (!i->isSelected()) continue;

        group = dynamic_cast<Group*>(i);
        //qDebug() << "group: " << group;
        auto arr = group->getObservers();
        for (auto j : arr) {
            j->remove();
        }
        result = group->returnAndClear();
        break;
    }
    for (auto j : result) {
        //qDebug() << "UNGROUP";
        container_.push_back(j);
    }
    group_ = group;
    shapes_ = result;
    container_.erase(std::find(container_.begin(), container_.end(), group_));
    //qDebug() << group_;
    return true;
}

void UnGroupCommand::unexecute() {
    //qDebug() << "unexec ungroup";
    if (group_ == nullptr) return;
    for (auto it = shapes_.begin(); it != shapes_.end(); it++) {
        group_->addShape(*it);
        container_.erase(std::find(container_.begin(), container_.end(), *it));
    }
    //qDebug() << "almost done unexec ungroup";
    container_.push_back(group_);
}

Command* UnGroupCommand::clone() {
    return new UnGroupCommand(container_);
}