#include "resizecommand.h"

ResizeCommand::ResizeCommand() : dx_(0), shape_(nullptr) {}

ResizeCommand::ResizeCommand(int dx, const QRect& border) : dx_(dx), shape_(nullptr), canvas_border_(border) {}

bool ResizeCommand::execute(Shape* shape) {
    shape_ = shape;
    if (shape_ != nullptr) {
        shape_->resize(dx_);
        shape_->updateShape();
        if (!canvas_border_.contains(shape_->getBorders())) {
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
    return new ResizeCommand(dx_, canvas_border_);
}