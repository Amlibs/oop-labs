#include "view.h"
#include <QString>

ViewWidget::ViewWidget() : QWidget() {
    layout = new QVBoxLayout(this);
    this->setLayout(layout);
    spin_box = new QSpinBox();
    slider = new QSlider(Qt::Horizontal);
    line_edit = new QLineEdit();
    layout->addWidget(spin_box);
    layout->addWidget(slider);
    layout->addWidget(line_edit);

    connect(spin_box, &QSpinBox::editingFinished, this, [=](){
        emit valueEdited(QString::number(spin_box->value()));
    });

    connect(slider, &QSlider::sliderReleased, this, [=](){
        emit valueEdited(QString::number(slider->value()));
    });

    connect(line_edit, &QLineEdit::editingFinished, this, [=](){
        emit valueEdited(line_edit->text());
    });
}

void ViewWidget::setValue(int value) {
    spin_box->setValue(value);
    slider->setValue(value);
    line_edit->setText(QString::number(value));
}