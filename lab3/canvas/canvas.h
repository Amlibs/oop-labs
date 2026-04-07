#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include <list>

#include "../factory/factory.h"
#include "../commands/movecommand.h"
#include "../commands/resizecommand.h"
#include "../commands/changecolorcommand.h"

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
    
    QPoint coordinate_;
    Container container_;
    Factory* factory_;
    std::list<Command*> history;
};