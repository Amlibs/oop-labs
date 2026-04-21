#pragma once

#include <list>
#include "command.h"
#include "arrowlink.h"

class LinkCommand : public Command {
 public:
    LinkCommand(Shape*, Shape*, ArrowLink*, std::list<Observer*>&);
	bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command *clone() override;
	~LinkCommand() { };
 private:
    ArrowLink* arrow_;
    std::list<Observer*>& arrows_;
    Shape* from_;
    Shape* to_;
};