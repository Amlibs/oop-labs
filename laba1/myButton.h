#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton {
    Q_OBJECT

 public:
    MyButton(const QString& text = "", QWidget* parent = nullptr);

    void paintEvent(QPaintEvent* event) override;
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void timerEvent(QTimerEvent* event) override;
};

#endif