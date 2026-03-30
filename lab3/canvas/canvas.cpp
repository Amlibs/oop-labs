#include "canvas.h"

#include <QPainter>
#include <QColor>

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    coordinate = event->pos();
    update();
}

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    Circle circle(coordinate, 30);
    circle.drawCircle(painter);
}