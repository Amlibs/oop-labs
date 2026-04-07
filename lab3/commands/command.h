#pragma once

#include "../shape/shape.h"

class Command {
 public:
	virtual void execute(Shape* shape) = 0;
	virtual void unexecute() = 0;
	virtual Command *clone() = 0;
	virtual ~Command() { };
};