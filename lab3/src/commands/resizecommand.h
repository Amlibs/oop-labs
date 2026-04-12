#pragma once

#include "command.h"

class ResizeCommand : public Command {
 public:
    ResizeCommand();
    ResizeCommand(int);
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
	~ResizeCommand() { };
 private:
    std::list<Shape*> shapes_;
    int dx_;
};
