#include "resizecommand.h"

ResizeCommand::ResizeCommand() : dx_(0), shape_(nullptr) {}

ResizeCommand::ResizeCommand(int dx) : dx_(dx), shape_(nullptr) {}

bool ResizeCommand::execute(Shape* shape) {
    shape_ = shape;
    if (shape_ != nullptr) {
        shape_->resize(dx_);
        shape_->updateShape();
        if (!shape_->isValid()) {
            this->unexecute();
            return false;
        }
    }
    return true;
}

void ResizeCommand::unexecute() {
    if (shape_ != nullptr) {
        shape_->resize(-dx_);
        shape_->updateShape();
    }
}

Command* ResizeCommand::clone() {
    return new ResizeCommand(dx_);
}