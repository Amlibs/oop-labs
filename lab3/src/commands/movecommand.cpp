#include "movecommand.h"

MoveCommand::MoveCommand() : dx_(0), dy_(0) {}

MoveCommand::MoveCommand(int dx, int dy) : dx_(dx), dy_(dy) {}

bool MoveCommand::execute(std::list<Shape*>& shapes) {
    //shape_ = shape;
    bool flag = false;
    if (!shapes.empty()) {
        for (auto i : shapes) {
            if (!i->isSelected()) {
                continue;
            }
            flag = true;
            shapes_.push_back(i);
            //qDebug() << "exec in movecom";
            i->move(dx_, dy_);
            i->updateShape();
            if (!i->isValid()) {
                this->unexecute();
                return false;
            }
        }
        return flag;
    }
    return false;
}

void MoveCommand::unexecute() {
    qDebug() << "unmove";
    if (!shapes_.empty()) {
        for (auto i : shapes_) {
            i->move(-dx_, -dy_);
            i->updateShape();
        }
    }
}

Command* MoveCommand::clone() {
    return new MoveCommand(dx_, dy_);
}

