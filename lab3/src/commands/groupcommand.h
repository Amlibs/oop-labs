#pragma once

#include "command.h"
#include "shapegroup.h"
#include "arrowlink.h"

class GroupCommand : public Command {
 public:
    GroupCommand(std::list<Shape*>&, Group*, std::list<Observer*>&);
    ~GroupCommand() {}
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
 private:
    std::list<Shape*>& container_;
    Group* group_;
    std::unordered_map<Shape*, std::list<Observer*>> shape_to_arrows;
    std::list<Observer*>& arrows_;
    ArrowLink* group_link_;
};
