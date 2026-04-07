#pragma once

#include "command.h"

class MoveCommand : public Command {
 public:
    MoveCommand();
    MoveCommand(int, int);
    void execute(Shape*) override;
	void unexecute() override;
	Command* clone() override;
	~MoveCommand() { };
 private:
    Shape* shape_;
    int dx_;
    int dy_;
};
