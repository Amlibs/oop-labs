#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>

class CanvasWidget : public QWidget {
    Q_OBJECT
 public:
    CanvasWidget() {

    }
 private:
    void mousePressEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;

    QPoint coordinate;
};