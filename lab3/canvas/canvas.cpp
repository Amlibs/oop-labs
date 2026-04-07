#include "canvas.h"

#include <QPainter>
#include <QColor>
#include <QDebug>

CanvasWidget::CanvasWidget(Factory* factory) : factory_(factory) {
    setFocusPolicy(Qt::StrongFocus);
}

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
        Shape* shape = factory_->createShapes(coordinate_);
        if (shape == nullptr) {
            //qDebug() << "nullptr";
            return;
        }
        container_.add(shape);
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
    MoveCommand* new_command = nullptr;
    if (event->key() == Qt::Key_Left) {
        new_command = new MoveCommand(-20, 0);
    }
    if (event->key() == Qt::Key_Up) {
        new_command = new MoveCommand(0, -20);
    }
    if (event->key() == Qt::Key_Right) {
        new_command = new MoveCommand(20, 0);
    }
    if (event->key() == Qt::Key_Down) {
        new_command = new MoveCommand(0, 20);
    }
    if (new_command != nullptr) {
        container_.move(new_command, history);
    }
    if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_Z)) {
        //qDebug() << "ctrl z";
        if (!history.empty()) {
            Command* first = history.back();
            history.pop_back();
            first->unexecute();
            delete first;
        }
    }
    update();
}

CanvasWidget::~CanvasWidget() {
    for (auto i : history) {
        delete i;
    }
}