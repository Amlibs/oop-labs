#include "groupcommand.h"

GroupCommand::GroupCommand(std::list<Shape*>& container, Group* group, std::list<Observer*>& arrows) : container_ (container), group_(group), arrows_(arrows)  {}

bool GroupCommand::execute(std::list<Shape*>& shapes) {
    bool added = false;
    for (auto it = container_.begin(); it != container_.end();) {
        Shape* i = *it;
        if (!i->isSelected()) {
            it++;
            continue;
        }
        //qDebug() << "add group" << i << '\n';
        group_->addShape(i);
        auto arr = i->getObservers();
        shape_to_arrows[i] = arr;
        it = container_.erase(it);
        for (auto j : shape_to_arrows[i]) {
            //qDebug() << "hi";
            j->remove();
            auto ait = std::find(arrows_.begin(), arrows_.end(), j);
            if (ait != arrows_.end()) {
                qDebug() << "удалил";
                arrows_.erase(ait);
            }
            
        }
        //qDebug() << "hi11";
        added = true;
    }
    if (!added) {
        return false;
    }
    //qDebug() << group_ << '\n';
    container_.push_back(group_);
    //qDebug() << "hi222";
    return true;
}

void GroupCommand::unexecute() {
    auto result = group_->returnAndClear();
    for (auto i : result) {
        container_.push_back(i);
        for (auto j : shape_to_arrows[i]) {
            //qDebug() << "тест new logic";
            j->add();
            if (std::find(arrows_.begin(), arrows_.end(), j) == arrows_.end()) {
                //qDebug() << "добавил";
                arrows_.push_back(j);
            }
        }
    }
    container_.erase(std::find(container_.begin(), container_.end(), group_));
    delete group_;
}

Command* GroupCommand::clone() {
    return new GroupCommand(container_, group_, arrows_);
}