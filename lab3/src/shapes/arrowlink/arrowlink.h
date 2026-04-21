#pragma once 

#include <QRect>

#include "observer.h"
#include "drawable.h"
#include "shape.h"

class ArrowLink : public Observer, public Drawable {
 public:
    ArrowLink(Shape* , Shape*);
    ~ArrowLink() {};
    void onSubjectMove(Shape*, int, int, std::unordered_set<Shape*>&) override;
    void draw(QPainter&) override;
    void add();
    void remove();
    Shape* getFrom() override {
      return from_;
    }
    Shape* getTo() override {
      return to_;
    }
    void setFrom(Shape* s) override {
      from_ = s;
    }
    void setTo(Shape* s) override {
      to_ = s;
    }
 private:
    Shape* from_ = nullptr;
    Shape* to_ = nullptr;
    bool is_removed_ = false;
};