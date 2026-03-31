#include "model.h"
#include <algorithm>
#include <QString>

Model::Model(): a_(0), b_(0), c_(0) {}

Model::Model(QString a, QString b, QString c) {
    setA(a);
    setB(b);
    setC(c);
}

void Model::setA(QString a) {
    if (!IsNumber(a)) {
        return;
    }
    a_ = a.toInt();
    if (b_ < a_) {
        b_ = a_;
    }
    if (b_ > c_) {
        c_ = b_;
    }
    ValidateNumbers();
    //std::cout << "a: " << a << '\n';
}

void Model::setB(QString b) {
    if (!IsNumber(b)) {
        return;
    }
    b_ = b.toInt();
    if (b_ > c_) {
        b_ = c_;
    } else if (b_ < a_) {
        b_ = a_;
    }
    ValidateNumbers();
}

void Model::setC(QString c) {
    if (!IsNumber(c)) {
        return;
    }
    c_ = c.toInt();
    if (b_ > c_) {
        b_ = c_;
    }
    if (b_ < a_) {
        a_ = b_;
    }
    ValidateNumbers();
    //std::cout << "c: " << c_ << '\n';
}

void Model::ValidateNumbers() {
    if (a_ > 100 || b_ > 100 || c_ > 100) {
        a_ = 100;
        b_ = 100;
        c_ = 100;
    }
}

bool Model::IsNumber(QString x) {
    bool ok = true;
    x.toInt(&ok);
    return ok;
}