#pragma once

#include <QObject>

class Observer {
 public:
    virtual void onSubjectChanged() = 0;
	virtual ~Observer() { }
};