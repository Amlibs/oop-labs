#include "arrowlink.h"

ArrowLink::ArrowLink(Shape* from, Shape* to) : from_(from), to_(to) {
    qDebug() << "asdasdasd";
    from_->addObserver(this);
    to_->addObserver(this);
}

void ArrowLink::onSubjectMove(Shape* shape, int dx, int dy, std::unordered_set<Shape*>& visited) {
    qDebug() << "Реагирую на движение";
    if (shape == from_) {
        to_->move(dx, dy, visited);
        to_->updateShape();
    } else {
        from_->move(dx, dy, visited);
        from_->updateShape();
    }
}

void ArrowLink::draw(QPainter& painter) {
    if (is_removed_) return;
    //qDebug() << "рисую линию";
    QPoint center_from = from_->getCenter();
    QPoint center_to = to_->getCenter();
    painter.drawLine(center_from, center_to);
}

void ArrowLink::add() {
    is_removed_ = false;
    if (from_) from_->addObserver(this);
    if (to_) to_->addObserver(this);
}

void ArrowLink::remove() {
    is_removed_ = true;
    if (from_) from_->removeObserver(this);
    if (to_) to_->removeObserver(this);
}
