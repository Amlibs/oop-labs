#pragma once

#include "command.h"

class MoveCommand : public Command {
 public:
    MoveCommand();
    MoveCommand(int, int);
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
	~MoveCommand() { };
 private:
    std::list<Shape*> shapes_;
    int dx_;
    int dy_;
};
