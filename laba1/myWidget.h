#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <stack>
#include <QPushButton>
#include <QBoxLayout>

class MyWidget : public QWidget {
    Q_OBJECT

 public:
    MyWidget();

    void resizeEvent(QResizeEvent* event) override;
    void addButton();

 private:
    QBoxLayout* layout;
    int count;
};

#endif