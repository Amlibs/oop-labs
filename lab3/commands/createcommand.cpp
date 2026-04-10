#include "createcommand.h"

CreateCommand::CreateCommand(Shape* shape, std::list<Shape*>& container) : shape_(shape), container_(container) {}

bool CreateCommand::execute(std::list<Shape*>& shapes) {
    if (shape_ != nullptr) {
        //qDebug() << *it_;
        container_.push_back(shape_);
        return true;
    }
    return false;
}

void CreateCommand::unexecute() {
    it_ = std::find(container_.begin(), container_.end(), shape_);
    if (it_ != container_.end() && *it_ != nullptr) {
        qDebug() << "asdasd";
        container_.erase(it_);
        delete *it_;
    }
}

Command* CreateCommand::clone() {
    return new CreateCommand(shape_, container_);
}