#pragma once

#include "command.h"
#include "arrowlink.h"

class UnLinkCommand : public Command {
 public:
    UnLinkCommand(ArrowLink*, std::list<Observer*>&);
	bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command *clone() override;
	~UnLinkCommand() { };
 private:
    ArrowLink* arrow_;
    std::list<Observer*>& arrows_;
}; 