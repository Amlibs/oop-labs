#pragma once

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMouseEvent>
#include <unordered_map>
#include "../container/container.h"
#include "observer.h"
#include "shape.h"

class TreeShapeView : public QTreeWidget, public Observer {
   Q_OBJECT
 public:
    TreeShapeView(Container&, QWidget* parent = nullptr);
    ~TreeShapeView() {};
    void onSubjectChanged() override;
    void addShape(::Shape*);
    void selectionChanged(const QItemSelection& selected, const QItemSelection& deselected) override;
 private:
   Container& container_;
   std::unordered_map<::Shape*, QTreeWidgetItem*> shape_to_item_;
   std::unordered_map<QTreeWidgetItem*, ::Shape*> item_to_shape_;
   bool block = false;
};