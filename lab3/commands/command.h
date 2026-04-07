#pragma once

#include "../shape/shape.h"

class Command {
 public:
	virtual bool execute(Shape*) = 0;
	virtual void unexecute() = 0;
	virtual Command *clone() = 0;
	virtual ~Command() { };
};