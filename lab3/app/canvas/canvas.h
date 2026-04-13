#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QContextMenuEvent>
#include <QMenu>
#include <QString>
#include <list>

#include "../factory/factory.h"
#include "../container/container.h"
#include "movecommand.h"
#include "resizecommand.h"
#include "changecolorcommand.h"
#include "deletecommand.h"
#include "createcommand.h"
#include "groupcommand.h"
#include "ungroupcommand.h"
#include "multiplecommand.h"

class CanvasWidget : public QWidget {
    Q_OBJECT
 public:
    CanvasWidget(Factory*);
    ~CanvasWidget();
    void changeColor(QColor);
    void saveAllShapes(QString);
    void loadShapes(QString);
    void deleteAll();
 private:
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void contextMenuEvent(QContextMenuEvent*) override;
    bool hitInShape(Shape*, QPoint);

    QPoint coordinate_;
    Container container_;
    Factory* factory_;
    std::list<Command*> history;
};