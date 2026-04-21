#pragma once

#include <QObject>
#include <unordered_set>

class Shape;

class Observer {
 public:
    virtual void onSubjectChanged() {}
    virtual void onSubjectMove(Shape*, int, int, std::unordered_set<Shape*>&) {}
    virtual void add() {}
    virtual void remove() {}
    virtual Shape* getFrom() {return nullptr;}
    virtual Shape* getTo() {return nullptr;}
    virtual void setFrom(Shape*) {}
    virtual void setTo(Shape*) {}
	virtual ~Observer() { }
};