#include "multiplecommand.h"

bool MultipleCommand::execute(std::list<Shape*>& shapes) {
    bool res = true;
    for (auto i : commands_) {
        res = i->execute(shapes) && res;
    }
    return res;
}    

void MultipleCommand::unexecute() {
    for (auto i : commands_) {
        i->unexecute();
    }
}

Command* MultipleCommand::clone() {
    return new MultipleCommand(commands_);
}