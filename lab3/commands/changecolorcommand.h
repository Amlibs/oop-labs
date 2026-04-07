#pragma once

#include "command.h"

class ChangeColorCommand : public Command {
 public:
    ChangeColorCommand();
    ChangeColorCommand(QColor);
    bool execute(Shape*) override;
	void unexecute() override;
	Command* clone() override;
	~ChangeColorCommand() { };
 private:
    Shape* shape_;
    QColor color_;
    QColor prev_color_;
};
