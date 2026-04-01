#pragma onces
#include <iostream>
#include <QString>
#include <QObject>

class Model : public QObject {
    Q_OBJECT
 public:
    Model();
    Model(int, int, int);
    ~Model();
    void PrintAll() {
        std::cout << a_ << ' ' << b_ << ' ' << c_ << '\n';
    }
    int getA() {
      return a_;
    }
    int getB() {
      return b_;
    }
    int getC() {
      return c_;
    }
 public slots:
    void setA(int);
    void setB(int);
    void setC(int);
 signals:
    void valuesChanged(int, int, int);
 private:
    void validateNumbers();
    void load();
    void save();
    int a_;
    int b_;
    int c_;
};