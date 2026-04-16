#include "shapegroup.h"

Group::Group(QRect cr){
    canvas_border_ = cr;
}

Group::~Group() {
    for (auto i : group_) {
        delete i;
    }
    //qDebug() << "destructor group";
}

bool Group::hit(QPoint pos) {
    for (auto i : group_) {
        if (i->hit(pos)) {
            return true;
        }
    }
    return false;
}

void Group::draw(QPainter& painter) {
    for (auto i : group_) {
        i->draw(painter);
    }

    //qDebug() << "draw group";
    if (in_group) return;

    QPen pen(Qt::red);
    pen.setStyle(Qt::DashLine);
    pen.setWidth(2);

    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(border_);
}

void Group::resize(int x) {
    for (auto i : group_) {
        i->resize(x);
    }
}

bool Group::isPositiveLenght() {
    bool flag = true;
    for (auto i : group_) {
        flag = i->isPositiveLenght() && flag;
    }
    return flag;
}

void Group::updateShape() {
    for (auto i : group_) {
        i->updateShape();
    }
    setBorderGroup();
}

void Group::addShape(Shape* shape) {
    group_.push_back(shape);
    setBorderGroup();
    shape->setInGroup(true);
}

void Group::move(int dx, int dy) {
    //qDebug() << "move group" << dx << dy;
    for (auto i : group_) {
        i->move(dx, dy);
    }
}

void Group::setBorderGroup() {
    int min_x = 10e6;
    int min_y = 10e6;
    int max_x = 0;
    int max_y = 0;
    for (auto i : group_) {
        int tx;
        int ty;
        int bx;
        int by;
        i->getBorder().getCoords(&tx, &ty, &bx, &by);
        min_x = std::min(min_x, tx);
        min_y = std::min(min_y, ty);
        max_x = std::max(max_x, bx);
        max_y = std::max(max_y, by);
    }
    border_ = QRect(QPoint(min_x, min_y), QPoint(max_x, max_y));
    //qDebug() << border_ << "<- граница";
}

void Group::setSelect(bool select) {
    for (auto i : group_) {
        i->setSelect(select);
    }
}

bool Group::isSelected() {
    for (auto i : group_) {
        if (i->isSelected()) {
            return true;
        }
    }
    return false;
}

void Group::setColor(QColor color) {
    for (auto i : group_) {
        i->setColor(color);
    }
}

std::list<Shape*> Group::returnAndClear() {
    for (auto i : group_) {
        i->setInGroup(false);
    }
    std::list<Shape*> temp = group_;
    group_.clear();
    return temp;
}

void Group::save(QTextStream& stream) {
    stream << type() << ' ' << group_.size() << ' ' << canvas_border_.width() << ' ' << canvas_border_.height() << '\n';
    for (auto i : group_) {
        i->save(stream);
    }
}

void Group::load(QStringList& line) {
    canvas_border_ = QRect(0, 0, line[2].toInt(), line[3].toInt());
}

QString Group::type() {
    return "group";
}