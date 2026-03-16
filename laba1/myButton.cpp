#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include "myButton.h"
#include <QColor>
#include <QEvent>
#include <QEnterEvent>
#include <QRandomGenerator>
#include <QTimerEvent>

MyButton::MyButton(const QString& text, QWidget* parent) : QPushButton(text, parent) {
}

void MyButton::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    QRectF rectangle = rect().adjusted(10, 10, -10, -10);
    painter.setBrush(QColor(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256)));
    painter.drawRect(rectangle);
    painter.drawText(rectangle, Qt::AlignCenter, text());
}

void MyButton::enterEvent(QEnterEvent* event) {
    update();
    QPushButton::enterEvent(event);
}

void MyButton::leaveEvent(QEvent* event) {
    update();
    QPushButton::leaveEvent(event);
}

void MyButton::timerEvent(QTimerEvent* event) {
    update();
    QPushButton::leaveEvent(event);
}