#pragma once

#include "command.h"
#include "shapegroup.h"

class GroupCommand : public Command {
 public:
    GroupCommand(std::list<Shape*>&, Group*);
    ~GroupCommand() {}
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
 private:
    std::list<Shape*>& container_;
    Group* group_;
};
