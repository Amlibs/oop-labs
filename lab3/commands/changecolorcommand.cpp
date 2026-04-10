#include "changecolorcommand.h"

ChangeColorCommand::ChangeColorCommand(QColor color) : color_(color) {}

bool ChangeColorCommand::execute(std::list<Shape*>& shapes) {
    //shape_ = shape;
    if (!shapes.empty()) {
        for (auto i : shapes) {
            if (!i->isSelected()) {
                continue;
            }
            shapes_.push_back(std::make_pair(i, i->getColor()));
            i->setColor(color_);
        }
    }
    return true;
}

void ChangeColorCommand::unexecute() {
    qDebug() << "try return color";
    if (!shapes_.empty()) {
        for (auto i : shapes_) {
            i.first->setColor(i.second);
        }
    }
}

Command* ChangeColorCommand::clone() {
    return new ChangeColorCommand(color_);
}
