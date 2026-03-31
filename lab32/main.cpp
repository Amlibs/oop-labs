#include "./view/view.h"
#include <iostream>
#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow* main_widget = new QMainWindow();
    QHBoxLayout* layout = new QHBoxLayout();
    ViewWidget* view_widget = new ViewWidget();
    layout->addWidget(view_widget);
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