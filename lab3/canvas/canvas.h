#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QContextMenuEvent>
#include <QMenu>
#include <list>

#include "../factory/factory.h"
#include "../commands/movecommand.h"
#include "../commands/resizecommand.h"
#include "../commands/changecolorcommand.h"
#include "../commands/deletecommand.h"
#include "../commands/createcommand.h"

class CanvasWidget : public QWidget {
    Q_OBJECT
 public:
    CanvasWidget(Factory*);
    ~CanvasWidget();
    void changeColor(QColor);
 private:
    void mousePressEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void contextMenuEvent(QContextMenuEvent*) override;
    
    QPoint coordinate_;
    Container container_;
    Factory* factory_;
    std::list<Command*> history;
};