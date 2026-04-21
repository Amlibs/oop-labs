#include "linkcommand.h"

LinkCommand::LinkCommand(Shape* from, Shape* to, ArrowLink* arrow, std::list<Observer*>& arrows) : from_(from), to_(to), arrow_(arrow), arrows_(arrows) {}

bool LinkCommand::execute(std::list<Shape*>& shapes) {
    if (arrow_ != nullptr) {
        //qDebug() << "create ARROW" << arrow_;
        arrows_.push_back(arrow_);
        return true;
    }
    return false;
}

void LinkCommand::unexecute() {
    auto it_ = std::find(arrows_.begin(), arrows_.end(), arrow_);
    if (it_ != arrows_.end() && *it_ != nullptr) {
        //qDebug() << "link command";
        //qDebug() << "remove ARROW" << arrow_ << arrows_.size();
        arrow_->remove();
        delete *it_;
        arrows_.erase(it_);
        //qDebug() << "Длина arrow" << arrows_.size();
        //qDebug() << "link command2222";
    }
}

Command* LinkCommand::clone() {
    return new LinkCommand(from_, to_, arrow_, arrows_);
}