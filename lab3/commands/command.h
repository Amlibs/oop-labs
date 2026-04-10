#pragma once

#include <list>

#include "../shape/shape.h"

class Command {
 public:
	virtual bool execute(std::list<Shape*>&) = 0;
	virtual void unexecute() = 0;
	virtual Command *clone() = 0;
	virtual ~Command() { };
};