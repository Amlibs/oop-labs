#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColorDialog>
#include <QPushButton>
#include <QComboBox>
#include "./factory/factory.h"
#include "./canvas/canvas.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    auto factory = new Factory(QColor::fromRgb(153, 255, 204));
    auto canvas = new CanvasWidget(factory);
    auto main_widget = new QWidget();
    main_widget->resize(1000, 700);
    auto header = new QHBoxLayout();
    auto layout = new QVBoxLayout();
    auto color_button = new QPushButton("Выберите цвет");
    auto combo_box = new QComboBox();
    combo_box->addItem("Треугольник", static_cast<int>(ShapeType::Triangle));
    combo_box->addItem("Эллипс", static_cast<int>(ShapeType::Ellipse));
    combo_box->addItem("Круг", static_cast<int>(ShapeType::Circle));
    combo_box->addItem("Прямоугольник", static_cast<int>(ShapeType::Rectangle));
    combo_box->addItem("Квадрат", static_cast<int>(ShapeType::Square));
    main_widget->setLayout(layout);
    layout->addLayout(header);
    layout->addWidget(canvas);
    header->addWidget(combo_box);
    header->addWidget(color_button);

    QObject::connect(color_button, &QPushButton::clicked, [=](){
        QColor color = QColorDialog::getColor();
        if (color.isValid()) {
            factory->setColor(color);
            canvas->changeColor(color);
        }
    });

    QObject::connect(combo_box, &QComboBox::currentIndexChanged, [=](){
        factory->setType(static_cast<ShapeType>(combo_box->currentData().toInt()));
    });

    main_widget->show();
    return app.exec();
}