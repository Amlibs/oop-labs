#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <QSpinBox>
#include <QSlider>
#include <QLineEdit>

class ViewWidget : public QWidget {
    Q_OBJECT
 public:
    ViewWidget();
 public slots:
    void setValue(int);
 signals:
    void valueEdited(QString);
 private:
    QVBoxLayout* layout;
    QSpinBox* spin_box;
    QSlider* slider;
    QLineEdit* line_edit;
};