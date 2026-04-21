#include "deletecommand.h"

DeleteCommand::DeleteCommand(std::list<Shape*>& container, std::list<Observer*>& arrows) : container_ (container), arrows_(arrows) {
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
        auto arr = shape->getObservers();
        shape_to_arrows[shape] = arr;
        for (auto j : arr) {
            j->remove();
            arrows_.erase(std::find(arrows_.begin(), arrows_.end(), j));
        }
        shapes.erase(i);
    }
    return flag;
}

void DeleteCommand::unexecute() {
    for (auto i = shapes_.begin(); i != shapes_.end(); i++) {
        Shape* shape = *i;
        container_.push_back(shape);
        shape->setObservers(shape_to_arrows[shape]);
        for (auto j : shape_to_arrows[shape]) {
            j->add();
            arrows_.push_back(j);
        }
    }
    shapes_.clear();
}

Command* DeleteCommand::clone() {
    return new DeleteCommand(container_, arrows_);
}