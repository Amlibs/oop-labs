#pragma onces
#include <iostream>
#include <QString>
#include <QObject>

class Model : public QObject {
    Q_OBJECT
 public:
    Model();
    Model(QString, QString, QString);
    Model(int, int, int);
    void PrintAll() {
        std::cout << a_ << ' ' << b_ << ' ' << c_ << '\n';
    }
 public slots:
    void setA(QString);
    void setB(QString);
    void setC(QString);
 signals:
    void valuesChanged(int, int, int);
 private:
    void ValidateNumbers();
    bool IsNumber(QString);
    int a_;
    int b_;
    int c_;
};