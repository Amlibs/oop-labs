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
 private:
    Shape* from_ = nullptr;
    Shape* to_ = nullptr;
};