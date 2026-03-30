#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include "../circle/circle.h"

class CanvasWidget : public QWidget {
    Q_OBJECT
 public:
    CanvasWidget() {

    }
 private:
    void mousePressEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;

    QPoint coordinate;
    //Circle circle;
};