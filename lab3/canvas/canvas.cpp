#include "canvas.h"

#include <QPainter>
#include <QColor>
#include <QDebug>

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    coordinate_ = event->pos();
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;
    bool flag = false;
    //qDebug() << isCtrlPressed;
    for (auto i : container_) {
        bool hit = i->hit(coordinate_);
        i->setSelect(i->isSelected() & isCtrlPressed || hit);
        if (hit) {
            flag = true;
        }
    }
    if (!flag) {
        container_.add(new Triangle(coordinate_, 50));
    }
    update();
}

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    for (auto i : container_) {
        i->draw(painter);
    }
}

void CanvasWidget::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Delete) {
        container_.removeSelected();
    }
    update();
}