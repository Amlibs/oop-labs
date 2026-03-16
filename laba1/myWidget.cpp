#include "myWidget.h"
#include <QResizeEvent>
#include <stack>
#include <QPushButton>
#include <string>

MyWidget::MyWidget() : QWidget() {
    layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    this->setLayout(layout);
};

void MyWidget::resizeEvent(QResizeEvent* event) {
    addButton();
    QWidget::resizeEvent(event);
}

void MyWidget::addButton() {
    if (count++ < 10) {
        auto new_button = new QPushButton("новая кнопка", this);
        layout->addWidget(new_button);
    }
}