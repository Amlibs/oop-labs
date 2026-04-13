#pragma once

#include "command.h"

class CreateCommand : public Command {
 public:
    CreateCommand(std::list<Shape*>& container) : container_(container) {};
    CreateCommand(Shape*, std::list<Shape*>&);
    ~CreateCommand() {}
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
 private:
    Shape* shape_;
    std::list<Shape*>& container_;
    std::list<Shape*>::iterator it_;
};
