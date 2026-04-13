#include "canvas.h"

#include <QPainter>
#include <QColor>
#include <QDebug>

CanvasWidget::CanvasWidget(Factory* factory) : factory_(factory) {
    setFocusPolicy(Qt::StrongFocus);
    //setMouseTracking(true);
}

bool CanvasWidget::hitInShape(Shape* i, QPoint coordinate) {
    return i->hit(coordinate);
}

bool CanvasWidget::hitInResizeRect(Shape* i, QPoint coordinate) {
    return i->getResizeRect().contains(coordinate);
} 

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        return;
    }
    //qDebug() << event->pos();
    coordinate_ = event->pos();
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;
    bool haveSelect = container_.haveSelected();
    if (!isCtrlPressed) {
        for (auto i : container_) {
            i->setSelect(false);
        }
    }
    bool hit = false;
    //qDebug() << isCtrlPressed;
    for (auto it = container_.rbegin(); it != container_.rend(); it++) {
        Shape* i = *it;
        hit = hitInShape(i, coordinate_);
        bool hit_in_resizerect = hitInResizeRect(i, coordinate_);
        i->setSelect(i->isSelected() & isCtrlPressed || hit || hit_in_resizerect);
        if (hit_in_resizerect) {
            move_cursor = false;
            diag_cursor_ = true;
        }
        if (hit) {
            move_cursor = true;
            diag_cursor_ = false;
            break;
        }
    }
    if (!hit && !haveSelect) {
        Command* command = new CreateCommand(factory_->createShapes(coordinate_, this->contentsRect()), container_.getList());
        container_.apply(command, history);
        //qDebug() << "create";
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
    switch (event->key()) {
    case Qt::Key_Delete:
        new_command = new DeleteCommand(container_.getList());
        break;
    case Qt::Key_Left:
        new_command = new MoveCommand(-20, 0);
        break;
    case Qt::Key_Up:
        new_command = new MoveCommand(0, -20);
        break;
    case Qt::Key_Right:
        new_command = new MoveCommand(20, 0);
        break;
    case Qt::Key_Down:
        new_command = new MoveCommand(0, 20);
        break;
    case Qt::Key_Plus:
        new_command = new ResizeCommand(5);
        break;
    case Qt::Key_Minus:
        new_command = new ResizeCommand(-5);
        break;
    default:
        break;
    }
    if (new_command != nullptr) {
        //qDebug() << "call apply";
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
    delete new_command;
    update();
}

void CanvasWidget::changeColor(QColor color) {
    Command* new_command = new ChangeColorCommand(color);
    if (new_command != nullptr) {
        container_.apply(new_command, history);
    }
    update();
}

void CanvasWidget::saveAllShapes(QString file_name) {
    container_.saveAll(file_name);
}

void CanvasWidget::loadShapes(QString file_name) {
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        QString count = stream.readLine().trimmed();
        qDebug() << count;
        int cnt = count.toInt();
        std::list<Command*> commands;
        for (int i = 0; i < cnt; i++) {
            Shape* shape = factory_->createShapesFromFile(stream);
            if (shape == nullptr) {
                QMessageBox::critical(nullptr, "Ошибка", "Файл с неправильным форматом данных");
                return;
            }
            auto create_command = new CreateCommand(shape, container_.getList());
            commands.push_back(create_command);
        }
        auto new_command = new MultipleCommand(commands);
        container_.apply(new_command, history);
    }
    file.close();
    update();
}

void CanvasWidget::deleteAll() {
    for (auto i : container_) {
        i->setSelect(true);
    }
    auto new_command = new DeleteCommand(container_.getList());
    container_.apply(new_command, history);
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
        delete new_command;
    }
    if (selected_action == ungroup_action) {
        //qDebug() << "ungroup";
        auto new_command = new UnGroupCommand(container_.getList());
        container_.apply(new_command, history);
        delete new_command;
    }
    //qDebug() << "update()";
    update();
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        return;
    }
    bool hit = false;
    QPoint release_pos = event->pos();
    Command* new_command;
    if (diag_cursor_ == true) {
        QPoint delta_point = release_pos - coordinate_;
        if (delta_point == QPoint(0,0)) return; 
        //qDebug() << "new move command create" << coordinate_ << release_pos;
        new_command = new ResizeCommand(-delta_point.x());
        container_.apply(new_command, history);
        diag_cursor_ = false;
        setCursor(Qt::ArrowCursor);
    } else {
        for (auto i : container_) { 
            if (hitInShape(i, coordinate_) && i->isSelected()) {
                hit = true;
                break;
            }
        }
        if (!hit) {
            return;
        }
        QPoint delta_point = release_pos - coordinate_;
        if (delta_point == QPoint(0,0)) return; 
        //qDebug() << "new move command create" << coordinate_ << release_pos;
        new_command = new MoveCommand(delta_point.x(), delta_point.y());
        container_.apply(new_command, history);
    }
    delete new_command;
    update();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    if (move_cursor) {
        return;
    }
    QPoint coordinate = event->pos();
    //qDebug() << coordinate;
    Shape* hit_shape = nullptr;
    for (auto i : container_) {
        if (i->isSelected()) {
            hit_shape = i;
            break;
        }
    }
    if (hit_shape != nullptr && hitInResizeRect(hit_shape, coordinate)) {
        diag_cursor_ = true;
        //qDebug() << "popali";
    }

    if (diag_cursor_) {
        setCursor(Qt::SizeFDiagCursor);
    }
    //qDebug() << "popali фаеук";
    update();
}

CanvasWidget::~CanvasWidget() {
    //qDebug() << "destructor in canvas";
    for (auto i : history) {
        delete i;
    }
}
