#include "unlinkcommand.h"

UnLinkCommand::UnLinkCommand(ArrowLink* arrow, std::list<Observer*>& arrows) : arrow_(arrow), arrows_(arrows) {}

bool UnLinkCommand::execute(std::list<Shape*>& shapes) {
    if (arrow_ == nullptr) return false;
    arrow_->remove();
    arrows_.remove(arrow_);
    return true;
}

void UnLinkCommand::unexecute() {
    if (arrow_ == nullptr) return;
    arrow_->add();
    arrows_.remove(arrow_);

    if (std::find(arrows_.begin(), arrows_.end(), arrow_) == arrows_.end()) {
        arrows_.push_back(arrow_);
    }
}

Command* UnLinkCommand::clone() {
    return new UnLinkCommand(arrow_, arrows_);
}