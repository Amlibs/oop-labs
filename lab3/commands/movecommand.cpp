#include "movecommand.h"

MoveCommand::MoveCommand() : dx_(0), dy_(0), shape_(nullptr) {}

MoveCommand::MoveCommand(int dx, int dy, const QRect& border) : dx_(dx), dy_(dy), shape_(nullptr), canvas_border_(border) {}

bool MoveCommand::execute(Shape* shape) {
    shape_ = shape;
    if (shape_ != nullptr) {
        //qDebug() << "exec in comm";
        shape_->move(dx_, dy_);
        shape_->updateShape();
        if (!canvas_border_.contains(shape_->getBorders())) {
            this->unexecute();
            return false;
        }
    }
    return true;
}

void MoveCommand::unexecute() {
    if (shape_ != nullptr) {
        shape_->move(-dx_, -dy_);
        shape_->updateShape();
    }
}

Command* MoveCommand::clone() {
    return new MoveCommand(dx_, dy_, canvas_border_);
}

