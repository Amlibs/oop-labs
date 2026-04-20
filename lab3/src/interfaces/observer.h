#pragma once

#include <QObject>
#include <unordered_set>

class Shape;

class Observer {
 public:
    virtual void onSubjectChanged() {};
    virtual void onSubjectMove(Shape*, int, int, std::unordered_set<Shape*>&) {};
	virtual ~Observer() { }
};