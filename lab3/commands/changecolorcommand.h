#pragma once

#include "command.h"

class ChangeColorCommand : public Command {
 public:
    ChangeColorCommand();
    ChangeColorCommand(QColor);
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
	~ChangeColorCommand() { };
 private:
    std::list<std::pair<Shape*, QColor>> shapes_;
    QColor color_;
};
