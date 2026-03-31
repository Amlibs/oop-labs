#include "model.h"
#include <algorithm>
#include <QString>
#include <qDebug>
#include <iostream>
#include <fstream>
#include <qDebug>

Model::Model(): a_(0), b_(0), c_(0) {
    qDebug() << "asdasdasdasdafgfdgtrhtrhrth";
}

Model::Model(int a, int b, int c) {
    setA(QString::number(a));
    setB(QString::number(b));
    setC(QString::number(c));
}

Model::~Model() {
    qDebug() << "asdasdasd";
    save();
}

void Model::setA(QString a) {
    if (!isNumber(a)) {
        validateNumbers();
        return;
    }
    int a_i = a.toInt();
    if (a_ == a_i && a_ != 0) {
        return;
    }
    a_ = a_i;
    if (a_ < 0) {
        a_ = 0;
    }
    if (b_ < a_) {
        b_ = a_;
    }
    if (b_ > c_) {
        c_ = b_;
    }
    validateNumbers();
    //std::cout << "a: " << a << '\n';
}

void Model::setB(QString b) {
    if (!isNumber(b)) {
        validateNumbers();
        return;
    }
    int b_i = b.toInt();
    if (b_ == b_i) {
        return;
    }
    b_ = b_i;
    if (b_ < 0) {
        b_ = 0;
    }
    if (b_ > c_) {
        b_ = c_;
    } else if (b_ < a_) {
        b_ = a_;
    }
    validateNumbers();
}

void Model::setC(QString c) {
    if (!isNumber(c)) {
        validateNumbers();
        return;
    }
    int c_i = c.toInt();
    if (c_ == c_i) {
        return;
    }
    c_ = c_i;
    if (c_ < 0) {
        c_ = 0;
    }
    if (b_ > c_) {
        b_ = c_;
    }
    if (b_ < a_) {
        a_ = b_;
    }
    validateNumbers();
    //std::cout << "c: " << c_ << '\n';
}

void Model::validateNumbers() {
    if (a_ > 99 || b_ > 99 || c_ > 99) {
        a_ = 99;
        b_ = 99;
        c_ = 99;
    }
    //qDebug() << "emit";
    emit valuesChanged(a_, b_, c_);
}

bool Model::isNumber(QString x) {
    bool ok = true;
    x.toInt(&ok);
    return ok;
}

void Model::load() {
    int a = 0;
    int b = 0;
    int c = 0;
    std::ifstream in("state.txt");
    if (in.is_open()) {
        in >> a >> b >> c;
    }
    setA(QString::number(a));
    setB(QString::number(b));
    setC(QString::number(c));
}

void Model::save() {
    std::ofstream out("state.txt");
    if (out.is_open()) {
        out << a_ << " " << b_ << " " << c_; 
    }
}