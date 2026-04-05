#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QKeyEvent>
#include "../circle/circle.h"
#include "../container/container.h"
#include "../rectangle/rectangle.h"
#include "../square/square.h"

class CanvasWidget : public QWidget {
    Q_OBJECT
 public:
    CanvasWidget() {

    }
 private:
    void mousePressEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;

    QPoint coordinate_;
    Container container_;
};