#pragma once

#include "command.h"

class MultipleCommand : public Command {
 public:
    MultipleCommand(std::list<Command*> commands) : commands_(commands) {};
    ~MultipleCommand() {};
    bool execute(std::list<Shape*>&) override;
    void unexecute() override;
    Command* clone() override;
 private:
    std::list<Command*> commands_;
};