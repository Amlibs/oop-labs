#pragma once

#include "command.h"

class MoveCommand : public Command {
 public:
    MoveCommand();
    MoveCommand(int, int, const QRect&);
    bool execute(Shape*) override;
	void unexecute() override;
	Command* clone() override;
	~MoveCommand() { };
 private:
    Shape* shape_;
    int dx_;
    int dy_;
    QRect canvas_border_;
};
