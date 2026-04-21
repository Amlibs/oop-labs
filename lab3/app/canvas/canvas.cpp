#include "canvas.h"

#include <QPainter>
#include <QColor>
#include <QDebug>

CanvasWidget::CanvasWidget(Factory* factory, Container& container, ShapeType type, QColor color) : factory_(factory), container_(container), current_type_(type), color_(color), menu_(this) {
    setFocusPolicy(Qt::StrongFocus);
    group_action_ = menu_.addAction("Сгруппировать");
    ungroup_action_ = menu_.addAction("Разгруппировать");
    link_action_ = menu_.addAction("Связать");
    unlink_action_ = menu_.addAction("Отвязать");
    //setMouseTracking(true);
}

bool CanvasWidget::hitInShape(Shape* i, QPoint coordinate) {
    return i->hit(coordinate);
}

bool CanvasWidget::hitInResizeRect(Shape* i, QPoint coordinate) {
    return i->getResizeRect().contains(coordinate) && i->isSelected();
}

Shape* CanvasWidget::findTopHitShape(QPoint pos) {
    for (auto it = container_.rbegin(); it != container_.rend(); it++) {
        if (hitInShape((*it), pos)) {
            return *it;
        }
    }
    return nullptr;
}

Shape* CanvasWidget::findTopHitResizeRect(QPoint pos) {
    for (auto it = container_.rbegin(); it != container_.rend(); it++) {
        if (hitInResizeRect((*it), pos)) {
            return *it;
        }
    }
    return nullptr;
}

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        return;
    }
    //qDebug() << event->pos();
    coordinate_ = event->pos();
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;
    bool haveSelect = container_.haveSelected();

    Shape* shape = findTopHitShape(coordinate_);
    Shape* resize_rect = findTopHitResizeRect(coordinate_);

    if (!isCtrlPressed) {
        container_.setAllSelect(false);
    }

    if (resize_rect != nullptr) {
        container_.setShapeSelect(resize_rect, true);
        mouse_mode_ = MouseType::Resize;
        update();
        return;
    }

    if (shape != nullptr) {
        container_.setShapeSelect(shape, true);
        mouse_mode_ = MouseType::Move;
        update();
        return;
    }

    if (haveSelect) {
        container_.setAllSelect(false);
        update();
        return;
    }
    Shape* shape_add = factory_->createShapes(current_type_, coordinate_, this->contentsRect(), color_);
    Command* command = new CreateCommand(
        shape_add,
        container_.getList());
    container_.apply(command, history);
    //container_.add(shape_add);
    //update();
}

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    //qDebug() << "Вызываю draw для всех";
    //qDebug() << container_.getArrowsList().size();
    for (auto it = container_.arrowBegin(); it != container_.arrowEnd(); it++) {
        ArrowLink* i = (ArrowLink*)*it;
        i->draw(painter);
    }
    for (auto i : container_) {
        i->draw(painter);
    }
    for (auto i : container_) {
        i->drawResizeRect(painter);
    }
    //qDebug() << "вызвал";
}

void CanvasWidget::keyPressEvent(QKeyEvent* event) {
    Command* new_command = nullptr;
    QRect canvas_border = this->contentsRect();
    switch (event->key()) {
    case Qt::Key_Delete:
        new_command = new DeleteCommand(container_.getList(), container_.getArrowsList());
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
        container_.apply(history);
    }
    delete new_command;
    update();
}

void CanvasWidget::changeColor(QColor color) {
    color_ = color;
    Command* new_command = new ChangeColorCommand(color_);
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
    ShapeLoaderFromFile loader;
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        QString count = stream.readLine().trimmed();
        qDebug() << count;
        int cnt = count.toInt();
        std::list<Command*> commands;
        for (int i = 0; i < cnt; i++) {
            Shape* shape = loader.loadShape(stream, factory_);
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
    container_.setAllSelect(true);
    auto new_command = new DeleteCommand(container_.getList(), container_.getArrowsList());
    container_.apply(new_command, history);
    update();
}

void CanvasWidget::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    container_.setNewBorder(this->contentsRect());
    update();
}

void CanvasWidget::contextMenuEvent(QContextMenuEvent* event) { 
    group_action_->setEnabled(container_.haveSelected());
    ungroup_action_->setEnabled(container_.haveSelectedGroup());
    link_action_->setEnabled(container_.countSelected() == 2);
    unlink_action_->setEnabled(container_.getArrowsList().size() >= 1);
    qDebug() << container_.getArrowsList().size();
    QAction* selected_action = menu_.exec(event->globalPos());
    if (selected_action == group_action_) {
        auto group = new Group(this->rect());
        auto new_command = new GroupCommand(container_.getList(), group, container_.getArrowsList());
        container_.apply(new_command, history);
        delete new_command;
    }
    if (selected_action == ungroup_action_) {
        auto new_command = new UnGroupCommand(container_.getList());
        container_.apply(new_command, history);
        delete new_command;
    }
    if (selected_action == link_action_) {
        std::pair<Shape*, Shape*> pair = container_.getTwoSelected();
        auto arrow = new ArrowLink(pair.first, pair.second);
        Command* new_command = new LinkCommand(pair.first, pair.second, arrow, container_.getArrowsList());
        container_.apply(new_command, history);
        delete new_command;
        //container_.addArrow(arrow);
    }
    if (selected_action == unlink_action_) {
        std::pair<Shape*, Shape*> pair = container_.getTwoSelected();
        ArrowLink* link = container_.findLink(pair.first, pair.second);
        Command* new_command = new UnLinkCommand(link, container_.getArrowsList());
        container_.apply(new_command, history);
        delete new_command;
    }
    update();
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        return;
    }
    QPoint release_pos = event->pos();
    QPoint delta_point = release_pos - coordinate_;
    if (delta_point == QPoint(0,0)) {
        setCursor(Qt::ArrowCursor);
        return;
    }
    Command* new_command = nullptr;
    switch (mouse_mode_) {
        case MouseType::Move:
            new_command = new MoveCommand(delta_point.x(), delta_point.y());
            break;
        case MouseType::Resize:
            new_command = new ResizeCommand(-delta_point.x());
        default:
            break;
    }

    if (new_command != nullptr) {
        container_.apply(new_command, history);
        delete new_command;
    }

    setCursor(Qt::ArrowCursor);
    mouse_mode_ = MouseType::Default;
    update();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        return;
    }

    switch (mouse_mode_) {
        case MouseType::Default:
            setCursor(Qt::ArrowCursor);
            break;
        case MouseType::Move:
            setCursor(Qt::ClosedHandCursor);
            break;
        case MouseType::Resize:
            setCursor(Qt::SizeFDiagCursor);
            break;
        default:
            break;
    }

    update();
}

void CanvasWidget::onSubjectChanged() {
    //qDebug() << "CanvaWidget::onSubjectChanged";
    update();
}

CanvasWidget::~CanvasWidget() {
    //qDebug() << "destructor in canvas";
    for (auto i : history) {
        delete i;
    }
}
