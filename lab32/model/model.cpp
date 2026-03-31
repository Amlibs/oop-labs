#include "model.h"
#include <algorithm>
#include <QString>

Model::Model(): a_(0), b_(0), c_(0) {}

Model::Model(int a, int b, int c) {
    setA(QString::number(a));
    setB(QString::number(b));
    setC(QString::number(c));
}

void Model::setA(QString a) {
    if (!IsNumber(a)) {
        return;
    }
    int a_i = a.toInt();
    if (a_ == a_i) {
        return;
    }
    a_ = a_i;
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
    int b_i = b.toInt();
    if (b_ == b_i) {
        return;
    }
    b_ = b_i;
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
    int c_i = c.toInt();
    if (c_ == c_i) {
        return;
    }
    c_ = c_i;
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
    emit valuesChanged(a_, b_, c_);
}

bool Model::IsNumber(QString x) {
    bool ok = true;
    x.toInt(&ok);
    return ok;
}