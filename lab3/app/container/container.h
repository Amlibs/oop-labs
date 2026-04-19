#pragma once

#include "shape.h"
#include "command.h"
#include "factory.h"
#include "observer.h"
//#include "../treeshapeview/treeshapeview.h"
//#include <vector>
#include <list>
#include <QString>
#include <QFile>
#include <QMessageBox>

class Container {
 public:
    //Container(TreeShapeView*);
    ~Container();
    void add(Shape*);
    void removeSelected();
    void apply(Command*, std::list<Command*>&);
    void apply(std::list<Command*>&);
    void setNewBorder(QRect);
    void saveAll(QString);
    void loadAll(QString, Factory*, Command*);
    std::list<Shape*>::iterator find(Shape*);
    auto begin() {
        return container_.begin();
    }
    auto end() {
        return container_.end();
    }
    auto rbegin() {
        return container_.rbegin();
    }
    auto rend() {
        return container_.rend();
    }
    std::list<Shape*>& getList() {
        return container_;
    }
    bool haveSelectedGroup() {
        bool have = false;
        int count = 0;
        for (auto i : container_){
            if (i->isGroup() && i->isSelected()) {
                have = true;
                count++;
            }
        }
        return (have && count < 2);
    }
    bool haveSelected() {
        bool have = false;
        for (auto i : container_){
            if (i->isSelected()) {
                have = true;
                break;
            }
        }
        return have;
    }
    void setAllSelect(bool b) {
        for (auto i : container_) {
            i->setSelect(b);
        }
        notifyEveryone();
    }
    void setShapeSelect(Shape* shape, bool b){
        shape->setSelect(b);
        notifyEveryone();
    }
    void addObserver(Observer* o) {
        //qDebug() << "ble ble ble" << observers_.size();
		observers_.push_back(o);
        //qDebug() << "bla bla bla" << observers_.size();
	}

	void notifyEveryone() {
        qDebug() << "notify";
		for (const auto &o : observers_) {
            //qDebug() << "notify obs";
			o->onSubjectChanged();
        }
	}

    
 private:
    std::list<Shape*> container_;
    std::list<Observer*> observers_;
    //TreeShapeView* tree_;
};