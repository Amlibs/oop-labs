#include "view.h"
#include <QSpinBox>
#include <QSlider>
#include <QLineEdit>

ViewWidget::ViewWidget() : QWidget() {
    layout = new QVBoxLayout(this);
    this->setLayout(layout);
    QSpinBox* spin_box = new QSpinBox();
    QSlider* slider = new QSlider();
    QLineEdit* line_edit = new QLineEdit();
    layout->addWidget(spin_box);
    layout->addWidget(slider);
    layout->addWidget(line_edit);
}