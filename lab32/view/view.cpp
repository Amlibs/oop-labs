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
        emit valueEdited(spin_box->value());
    });

    connect(slider, &QSlider::sliderReleased, this, [=](){
        emit valueEdited(slider->value());
    });

    connect(line_edit, &QLineEdit::editingFinished, this, [=](){
        if (isNumber(line_edit->text())) {
            emit valueEdited(line_edit->text().toInt());
        }
    });
}

void ViewWidget::setValue(int value) {
    spin_box->blockSignals(true);
    slider->blockSignals(true);
    line_edit->blockSignals(true);

    spin_box->setValue(value);
    slider->setValue(value);
    line_edit->setText(QString::number(value));

    spin_box->blockSignals(false);
    slider->blockSignals(false);
    line_edit->blockSignals(false);
}

bool ViewWidget::isNumber(QString x) {
    bool ok = true;
    x.toInt(&ok);
    return ok;
}