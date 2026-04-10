#include "resizecommand.h"

ResizeCommand::ResizeCommand() : dx_(0) {}

ResizeCommand::ResizeCommand(int dx) : dx_(dx) {}

bool ResizeCommand::execute(std::list<Shape*>& shapes) {
    //shape_ = shape;
    if (!shapes.empty()) {

        for (auto i : shapes) {
            if (!i->isSelected()) {
                continue;
            }
            shapes_.push_back(i);
            //qDebug() << "exec in movecom";
            i->resize(dx_);
            i->updateShape();
            if (!i->isValid()) {
                this->unexecute();
                return false;
            }
        }
    }
    return true;
}

void ResizeCommand::unexecute() {
    if (!shapes_.empty()) {
        for (auto i : shapes_) {
            i->resize(-dx_);
            i->updateShape();
        }
    }
}

Command* ResizeCommand::clone() {
    return new ResizeCommand(dx_);
}