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
    if (event->key() == Qt::Key_Left) {
        MoveCommand* new_command = new MoveCommand(-20, 0);
        container_.move(new_command);
        history.push_back(new_command);
    }
    if (event->key() == Qt::Key_Up) {
        MoveCommand* new_command = new MoveCommand(0, -20);
        container_.move(new_command);
        history.push_back(new_command);
        //qDebug() << "UPUPUPUPUPUPUPUPUPUPUPU";
    }
    if (event->key() == Qt::Key_Right) {
        MoveCommand* new_command = new MoveCommand(20, 0);
        container_.move(new_command);
        history.push_back(new_command);
    }
    if (event->key() == Qt::Key_Down) {
        MoveCommand* new_command = new MoveCommand(0, 20);
        container_.move(new_command);
        history.push_back(new_command);
    }
    update();
}

CanvasWidget::~CanvasWidget() {
    for (auto i : history) {
        delete i;
    }
}