#include <iostream>
#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>

#include "./view/view.h"
#include "./model/model.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget* main_widget = new QWidget();
    QHBoxLayout* layout = new QHBoxLayout();
    main_widget->setLayout(layout);
    ViewWidget* view_widget_for_a = new ViewWidget();
    ViewWidget* view_widget_for_b = new ViewWidget();
    ViewWidget* view_widget_for_c = new ViewWidget();
    layout->addWidget(view_widget_for_a);
    layout->addWidget(view_widget_for_b);
    layout->addWidget(view_widget_for_c);

    Model* model = new Model();

    QObject::connect(view_widget_for_a, &ViewWidget::valueEdited, model, &Model::setA);

    QObject::connect(view_widget_for_b, &ViewWidget::valueEdited, model, &Model::setB);

    QObject::connect(view_widget_for_c, &ViewWidget::valueEdited, model, &Model::setC);

    QObject::connect(model, &Model::valuesChanged, view_widget_for_a,
        [=](int a, int b, int c) {
            view_widget_for_a->setValue(a);
        });

    QObject::connect(model, &Model::valuesChanged, view_widget_for_b, 
        [=](int a, int b, int c) {
            view_widget_for_b->setValue(b);
        });

    QObject::connect(model, &Model::valuesChanged, view_widget_for_c, 
        [=](int a, int b, int c) {
            view_widget_for_c->setValue(c);
        });

    main_widget->show();
    return app.exec();
}


/*
int main() {
    Model model(QString::number(5), QString::number(11), QString::number(4));
    while (true) {
        char s;
        std::cin >> s;
        QString x;
        QTextStream qtin(stdin); 
        x = qtin.readLine();
        //std::cin >> x;
        if (s == 'a') {
            std::cout << "aaaaaa" << '\n';
            model.setA(x);
        } else if (s == 'b') {
            std::cout << "bbbbbbbbbbb" << '\n';
            model.setB(x);
        } else if (s == 'c') {
            std::cout << "cccccccccccc" << '\n';
            model.setC(x);
        }
        model.PrintAll();
    }
    
    //std::cout << "as,smdkmasdkofmasdf" << '\n';

    return 0;
}*/