#include "model.h"
#include <algorithm>
#include <QString>
#include <qDebug>
#include <iostream>
#include <fstream>
#include <qDebug>

Model::Model() {
    load();
    //qDebug() << "asdasdasdasdafgfdgtrhtrhrth";
}

Model::Model(int a, int b, int c) {
    setA(a);
    setB(b);
    setC(c);
}

Model::~Model() {
    //qDebug() << "asdasdasd";
    save();
}

void Model::setA(int a) {
    if (a_ == a && a_ != 0) {
        return;
    }
    a_ = a;
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

void Model::setB(int b) {
    if (b_ == b) {
        return;
    }
    b_ = b;
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

void Model::setC(int c) {
    if (c_ == c) {
        return;
    }
    c_ = c;
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

void Model::load() {
    int a = 0;
    int b = 0;
    int c = 0;
    std::ifstream in("state.txt");
    if (in.is_open()) {
        in >> a >> b >> c;
    }
    a_ = a;
    b_ = b;
    c_ = c;
}

void Model::save() {
    std::ofstream out("state.txt");
    if (out.is_open()) {
        out << a_ << " " << b_ << " " << c_; 
    }
}