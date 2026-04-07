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
    //qDebug() << this->rect();
    for (auto i : container_) {
        i->draw(painter);
    }
}

void CanvasWidget::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Delete) {
        container_.removeSelected();
    }
    Command* new_command = nullptr;
    QRect canvas_border = this->contentsRect();
    if (event->key() == Qt::Key_Left) {
        new_command = new MoveCommand(-20, 0, canvas_border);
    }
    if (event->key() == Qt::Key_Up) {
        new_command = new MoveCommand(0, -20, canvas_border);
    }
    if (event->key() == Qt::Key_Right) {
        new_command = new MoveCommand(20, 0, canvas_border);
    }
    if (event->key() == Qt::Key_Down) {
        new_command = new MoveCommand(0, 20, canvas_border);
    }
    if (event->key() == Qt::Key_Plus) {
        new_command = new ResizeCommand(5, canvas_border);
    }
    if (event->key() == Qt::Key_Minus) {
        new_command = new ResizeCommand(-5, canvas_border);
    }
    if (new_command != nullptr) {
        container_.apply(new_command, history);
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

void CanvasWidget::changeColor(QColor color) {
    Command* new_command = new ChangeColorCommand(color);
    if (new_command != nullptr) {
        container_.apply(new_command, history);
    }
    update();
}

CanvasWidget::~CanvasWidget() {
    for (auto i : history) {
        delete i;
    }
}