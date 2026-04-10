#pragma once

#include "command.h"

class DeleteCommand : public Command {
 public:
    DeleteCommand(std::list<Shape*>&);
    ~DeleteCommand() {
        for (auto i : shapes_) {
            delete i;
        }
    };
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
 private:
    std::list<Shape*> shapes_;
    std::list<Shape*>& container_;
};
