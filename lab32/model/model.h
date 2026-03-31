#pragma onces
#include <iostream>
#include <QString>

class Model {
 public:
    Model();
    Model(QString, QString, QString);
    void setA(QString);
    void setB(QString);
    void setC(QString);
    void PrintAll() {
        std::cout << a_ << ' ' << b_ << ' ' << c_ << '\n';
    }
 private:
    void ValidateNumbers();
    bool IsNumber(QString);
    int a_;
    int b_;
    int c_;
};