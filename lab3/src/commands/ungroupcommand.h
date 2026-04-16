#pragma once

#include "command.h"
#include "shapegroup.h"

class UnGroupCommand : public Command {
 public:
    UnGroupCommand(std::list<Shape*>&);
    ~UnGroupCommand() {
        //qDebug() << "delete ungroup";
        if (std::find(container_.begin(), container_.end(), group_) == container_.end()) delete group_;
    }
    bool execute(std::list<Shape*>&) override;
	void unexecute() override;
	Command* clone() override;
 private:
    std::list<Shape*>& container_;
    std::list<Shape*> shapes_;
    Group* group_;
};
