#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QContextMenuEvent>
#include <QString>
#include <QMenu>
#include <list>

#include "factory.h"
#include "../container/container.h"
#include "movecommand.h"
#include "resizecommand.h"
#include "changecolorcommand.h"
#include "deletecommand.h"
#include "createcommand.h"
#include "groupcommand.h"
#include "ungroupcommand.h"
#include "multiplecommand.h"
#include "linkcommand.h"
#include "unlinkcommand.h"
#include "mousetype.h"
#include "../loader/loaderfromfile.h"
#include "observer.h"

class CanvasWidget : public QWidget, public Observer {
    Q_OBJECT
 public:
    CanvasWidget(Factory*, Container&, ShapeType type, QColor color);
    ~CanvasWidget();
    void changeColor(QColor);
    void saveAllShapes(QString);
    void loadShapes(QString);
    void deleteAll();
    void setType(ShapeType type) {
      current_type_ = type;
    }
    void onSubjectChanged() override;
 private:
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void contextMenuEvent(QContextMenuEvent*) override;
    bool hitInShape(Shape*, QPoint);
    bool hitInResizeRect(Shape*, QPoint);
    Shape* findTopHitShape(QPoint);
    Shape* findTopHitResizeRect(QPoint);

    QPoint coordinate_;
    Container& container_;
    Factory* factory_;
    //bool diag_cursor_ = false;
    MouseType mouse_mode_ = MouseType::Default;
    std::list<Command*> history;
    QMenu menu_;
    QAction* group_action_;
    QAction* ungroup_action_;
    QAction* link_action_;
    QAction* unlink_action_;
    ShapeType current_type_;
    QColor color_;
};