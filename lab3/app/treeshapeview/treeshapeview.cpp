#include "treeshapeview.h"

#include <QDebug>

TreeShapeView::TreeShapeView(Container& container, QWidget* parent) : container_(container), QTreeWidget(parent) {
    this->setColumnCount(1);
    this->setHeaderLabel("Фигуры");
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
}
/*
void TreeShapeView::addShape(::Shape* shape) {
    qDebug() << "testtestik";
    //auto tree_widget_ = shape->getWidgetItem(this);
    this->insertTopLevelItem(0, tree_widget_);
    shape_to_item_[shape] = tree_widget_;
    update();
}*/

void TreeShapeView::onSubjectChanged() {
    qDebug() << "someone notify me";
    if (block) return;
    block = true;
    for (auto i : container_) {
        if (shape_to_item_.find(i) != shape_to_item_.end()) {
            shape_to_item_[i]->setSelected(i->isSelected());
            continue;
        }
        auto tree_widget_ = i->getWidgetItem();
        this->insertTopLevelItem(0, tree_widget_);
        shape_to_item_[i] = tree_widget_;
        item_to_shape_[tree_widget_] = i;
        //qDebug() << "ll";
    }
    //qDebug() << "ya tyt";
    for (auto it = shape_to_item_.begin(); it != shape_to_item_.end();) {
        //qDebug() << "nachalo";
        ::Shape* i = it->first;
        QTreeWidgetItem* item = it->second;
        if (container_.find(i) != container_.end()) {
            it++;
            continue;
        }
        //qDebug() << "ya tam";
        int index = this->indexOfTopLevelItem(item);
        if (index != -1) {
            auto temp = this->takeTopLevelItem(index);
            delete temp;
        }
        //qDebug() << "daleko";
        auto item_it = item_to_shape_.find(item);
        if (item_it != item_to_shape_.end()) {
            item_to_shape_.erase(item_it);
        }
        it = shape_to_item_.erase(it);
        //qDebug() << "blizko";
        //qDebug() << i;
    }
    block = false;
    update();
}

void TreeShapeView::selectionChanged(const QItemSelection& selected, const QItemSelection& deselected) {
    QTreeWidget::selectionChanged(selected, deselected);
    if (block) return;
    block = true;
    qDebug() << "selectionChanged";
    for (auto index : deselected.indexes()) {
        auto item = this->itemFromIndex(index);
        auto it = item_to_shape_.find(item);
        if (it != item_to_shape_.end()) {
            ::Shape* shape = it->second;
            container_.setShapeSelect(shape, false);
        }
    }

    for (auto index : selected.indexes()) {
        auto item = this->itemFromIndex(index);
        auto it = item_to_shape_.find(item);
        if (it != item_to_shape_.end()) {
            ::Shape* shape = it->second;
            container_.setShapeSelect(shape, true);
        }
    }
    block = false;
}