#include "container.h"
#include <QDebug>

Container::~Container() {
    for (auto i : container_) {
        delete i;
    }
    qDebug() << "delete";
}

void Container::add(Shape* shape) {
    container_.push_back(shape);
}

void Container::removeSelected() {
    container_.remove_if([=](Shape* shape) {
        if (shape->isSelected()) {
            delete shape;
            return true;
        }
        return false;
    });
}

void Container::apply(Command* command, std::list<Command*>& history) {
    auto clone_comand = command->clone();
    //qDebug() << "apply";
    if (!clone_comand->execute(container_)) {
        //qDebug() << "unapply";
        delete clone_comand;
        return;
    }
    history.push_back(clone_comand);
}

void Container::setNewBorder(QRect canvas_border) {
    for (auto i : container_) {
        i->setCanvasBorser(canvas_border);
    }
}

void Container::saveAll(QString file_name) {
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << container_.size() << '\n';
        for (auto i : container_) {
            i->save(stream);
        }
    }
    file.close();
}

void Container::loadAll(QString file_name, Factory* factory, Command* command) {

}