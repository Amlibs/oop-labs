#include "canvas.h"

#include <QPainter>
#include <QColor>

void CanvasWidget::mousePressEvent(QMouseEvent* event) {
    coordinate = event->pos();
    update();
}

void CanvasWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor::fromRgb(153, 255, 204), Qt::SolidPattern));
    painter.setPen(QColor::fromRgb(0, 204, 102));

    painter.drawEllipse(coordinate, 50, 50);
}