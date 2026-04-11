#include "ungroupcommand.h"

UnGroupCommand::UnGroupCommand(std::list<Shape*>& container) : container_ (container), group_(nullptr) {}

bool UnGroupCommand::execute(std::list<Shape*>& shapes) {
    for (auto i : container_) {
        if (!i->isGroup()) continue;

        if (!i->isSelected()) continue;

        Group* group = dynamic_cast<Group*>(i);
        auto result = group->returnAndClear();
        for (auto j : result) {
            container_.push_back(j);
        }
        group_ = group;
        shapes_ = result;
        container_.erase(std::find(container_.begin(), container_.end(), group_));
    }
    qDebug() << group_;
    return true;
}

void UnGroupCommand::unexecute() {
    qDebug() << "unexec ungroup";
    if (group_ == nullptr) return;
    for (auto it = shapes_.begin(); it != shapes_.end(); it++) {
        group_->addShape(*it);
        container_.erase(std::find(container_.begin(), container_.end(), *it));
    }
    qDebug() << "almost done unexec ungroup";
    container_.push_back(group_);
}

Command* UnGroupCommand::clone() {
    return new UnGroupCommand(container_);
}