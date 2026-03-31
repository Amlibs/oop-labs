#pragma once
#include <QWidget>
#include <QVBoxLayout>

class ViewWidget : public QWidget {
    Q_OBJECT
 public:
    ViewWidget();
 private:
    QVBoxLayout* layout;
};