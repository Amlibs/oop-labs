#include "movecommand.h"

MoveCommand::MoveCommand() : dx_(0), dy_(0) {}

MoveCommand::MoveCommand(int dx, int dy) : dx_(dx), dy_(dy) {}

bool MoveCommand::execute(std::list<Shape*>& shapes) {
    std::unordered_set<Shape*> visited;
    bool flag = false;

    for (auto i : shapes) {
        if (!i->isSelected()) {
            continue;
        }
        flag = true;
        shapes_.push_back(i);
        i->move(dx_, dy_, visited);
    }

    if (!flag) {
        return false;
    }

    for (auto i : visited) {
        i->updateShape();
    }

    int corrDx = 0;
    int corrDy = 0;

    for (auto i : visited) {
        auto p = i->getCorrections();
        corrDx = combineCorrection(corrDx, p.first);
        corrDy = combineCorrection(corrDy, p.second);
    }

    if (corrDx != 0 || corrDy != 0) {
        std::unordered_set<Shape*> temp;
        for (auto i : shapes_) {
            i->move(corrDx, corrDy, temp);
        }
        for (auto i : temp) {
            i->updateShape();
        }
    }

    dx_ += corrDx;
    dy_ += corrDy;

    return true;
}

void MoveCommand::unexecute() {
    qDebug() << "unmove";
    std::unordered_set<Shape*> visited;
    if (!shapes_.empty()) {
        for (auto i : shapes_) {
            i->move(-dx_, -dy_, visited);
            i->updateShape();
        }
    }
}

Command* MoveCommand::clone() {
    return new MoveCommand(dx_, dy_);
}

int MoveCommand::combineCorrection(int dx, int dy) {
    if (dx == 0) return dy;
    if (dy == 0) return dx;

    if (dx > 0 && dy > 0) {
        return std::max(dx, dy);
    }
    if (dx < 0 && dy < 0) {
        return std::min(dx, dy);
    }

    return dy;
}

