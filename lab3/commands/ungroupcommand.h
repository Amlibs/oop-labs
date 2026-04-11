#pragma once

#include "command.h"
#include "../shapegroup/shapegroup.h"

class UnGroupCommand : public Command {
 public:
    UnGroupCommand(std::list<Shape*>&);
    ~UnGroupCommand() {}
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
 private:
    std::list<Shape*>& container_;
    std::list<Shape*> shapes_;
    Group* group_;
};
