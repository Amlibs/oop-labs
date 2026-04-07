#include "changecolorcommand.h"

ChangeColorCommand::ChangeColorCommand(QColor color) : color_(color) {}

bool ChangeColorCommand::execute(Shape* shape) {
    shape_ = shape;
    if (shape_ != nullptr) {
        prev_color_ = shape_->getColor();
        shape_->setColor(color_);
    }
    return true;
}

void ChangeColorCommand::unexecute() {
    if (shape_ != nullptr) {
        shape_->setColor(prev_color_);
    }
}

Command* ChangeColorCommand::clone() {
    return new ChangeColorCommand(color_);
}
