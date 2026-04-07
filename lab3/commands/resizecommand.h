#pragma once

#include "command.h"

class ResizeCommand : public Command {
 public:
    ResizeCommand();
    ResizeCommand(int, const QRect&);
    bool execute(Shape*) override;
	void unexecute() override;
	Command* clone() override;
	~ResizeCommand() { };
 private:
    Shape* shape_;
    int dx_;
    QRect canvas_border_;
};
