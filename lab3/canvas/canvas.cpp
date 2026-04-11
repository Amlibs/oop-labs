#include "canvas.h"

#include <QPainter>
#include <QColor>
#include <QDebug>

CanvasWidget::CanvasWidget(Factory* factory) : factory_(factory) {
    setFocusPolicy(Qt::StrongFocus);
}

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        return;
    }
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
        Command* command = new CreateCommand(factory_->createShapes(coordinate_, this->contentsRect()), container_.getList());
        container_.apply(command, history);
        qDebug() << "create";
    }
    update();
}

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    //qDebug() << "Вызываю draw для всех";
    for (auto i : container_) {
        i->draw(painter);
    }
}

void CanvasWidget::keyPressEvent(QKeyEvent* event) {
    Command* new_command = nullptr;
    QRect canvas_border = this->contentsRect();
    if (event->key() == Qt::Key_Delete) {
        new_command = new DeleteCommand(container_.getList());
    }
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
    if (event->key() == Qt::Key_Plus) {
        new_command = new ResizeCommand(5);
    }
    if (event->key() == Qt::Key_Minus) {
        new_command = new ResizeCommand(-5);
    }
    if (new_command != nullptr) {
        qDebug() << "call apply";
        container_.apply(new_command, history);
    }
    if (event->keyCombination() == QKeyCombination(Qt::CTRL, Qt::Key_Z)) {
        qDebug() << "ctrl z";
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

void CanvasWidget::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    container_.setNewBorder(this->contentsRect());
    update();
}

void CanvasWidget::contextMenuEvent(QContextMenuEvent* event) { 
    QMenu menu(this);
    QAction* group_action = menu.addAction("Сгруппировать");
    group_action->setEnabled(container_.haveSelected());
    QAction* ungroup_action = menu.addAction("Разгруппировать");
    ungroup_action->setEnabled(container_.haveSelectedGroup());
    QAction* selected_action = menu.exec(event->globalPos());
    if (selected_action == group_action) {
        auto group = new Group(this->rect());
        auto new_command = new GroupCommand(container_.getList(), group);
        container_.apply(new_command, history);
    }
    if (selected_action == ungroup_action) {
        qDebug() << "ungroup";
        auto new_command = new UnGroupCommand(container_.getList());
        container_.apply(new_command, history);
    }
    //qDebug() << "update()";
    update();
}

CanvasWidget::~CanvasWidget() {
    qDebug() << "destructor in canvas";
    for (auto i : history) {
        delete i;
    }
}