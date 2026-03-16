#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QTabWidget>
#include <QBoxLayout>
#include <QWidget>
#include <QProgressBar>
#include <QDial>
#include <QAbstractSlider>
#include <QSlider>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QLabel>
#include <QMenuBar>
#include <QAction>
#include "myButton.h"
#include "myWidget.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow* main_widget = new QMainWindow();
    QWidget* central_widget = new QWidget(main_widget);
    QWidget* second_widget = new QWidget();

    auto second_widget_top = new QWidget(second_widget);
    auto second_widget_bottom = new QWidget(second_widget);
    QWidget* widget_for_button = new QWidget();
    auto four_widget = new MyWidget();

    QBoxLayout* layout = new QBoxLayout(QBoxLayout::LeftToRight, central_widget);
    auto layout_for_second_widget = new QVBoxLayout(second_widget);
    auto layout_for_second_widget_top = new QVBoxLayout(second_widget_top);
    auto layout_for_second_widget_bottom = new QHBoxLayout(second_widget_bottom);
    QBoxLayout* layout_for_button_widget = new QBoxLayout(QBoxLayout::LeftToRight, widget_for_button);
    auto layout_line_text = new QHBoxLayout();
    auto layout_time_edit = new QHBoxLayout();
    auto layout_date_edit = new QHBoxLayout();

    QProgressBar* progress_bar = new QProgressBar();
    progress_bar->setValue(0);

    QDial* dial = new QDial();
    auto slider = new QSlider();
    auto radio_button_1 = new QRadioButton("25%");
    auto radio_button_2 = new QRadioButton("50%");
    auto radio_button_3 = new QRadioButton("75%");
    auto radio_button_4 = new QRadioButton("100%");
    auto check_button_1 = new QCheckBox("+25%");
    auto check_button_2 = new QCheckBox("+25%");
    auto check_button_3 = new QCheckBox("+25%");
    auto check_button_4 = new QCheckBox("+25%");
    auto radio_button_group = new QButtonGroup();
    auto check_button_group = new QButtonGroup();
    auto v_layout_radio_button = new QVBoxLayout();
    auto v_layout_check_button = new QVBoxLayout();
    QPushButton* test_button = new QPushButton("Каждое нажатие +1%");

    auto test_button_2 = new MyButton("Кнопка меняет цвет\n при наведении мышкой\n и каждую секунду", widget_for_button);
    test_button_2->setFixedSize(200, 120);
    test_button_2->startTimer(1000);

    auto line_text = new QLineEdit();
    line_text->setMaxLength(100);
    auto date_edit = new QDateEdit();
    auto time_edit = new QTimeEdit();
    date_edit->setMinimumDate(QDate(2026, 1, 1));
    auto label_text = new QLabel("Каждый символ +1%");
    auto label_date_text = new QLabel("Чем ближе дата к сегодняшней, тем больше %");
    auto label_time_text = new QLabel("Чем ближе время к текущему, тем больше %");

    QMenuBar* menu_bar = main_widget->menuBar();
    QMenu* menu_1 = menu_bar->addMenu("Про кнопку");
    QAction* visiable_button = menu_1->addAction("Включить/выключить");
    visiable_button->setCheckable(true);
    visiable_button->setChecked(true);

    QTabWidget* tab_widget = new QTabWidget();  
    tab_widget->setTabPosition(QTabWidget::North);
    tab_widget->addTab(second_widget, "Первая");
    tab_widget->addTab(widget_for_button, "Вторая");
    tab_widget->addTab(four_widget, "Третья");

    main_widget->setCentralWidget(central_widget);
    central_widget->setLayout(layout);
    second_widget->setLayout(layout_for_second_widget);
    second_widget_top->setLayout(layout_for_second_widget_top);
    second_widget_bottom->setLayout(layout_for_second_widget_bottom);
    widget_for_button->setLayout(layout_for_button_widget);

    radio_button_group->addButton(radio_button_1, 1);
    radio_button_group->addButton(radio_button_2, 2);
    radio_button_group->addButton(radio_button_3, 3);
    radio_button_group->addButton(radio_button_4, 4);

    check_button_group->addButton(check_button_1, 1);
    check_button_group->addButton(check_button_2, 2);
    check_button_group->addButton(check_button_3, 3);
    check_button_group->addButton(check_button_4, 4);
    check_button_group->setExclusive(false);

    QObject::connect(visiable_button, &QAction::toggled, test_button, [=](){test_button->setVisible(visiable_button->isChecked());});
    QObject::connect(test_button, &QPushButton::clicked, progress_bar, [=](){progress_bar->setValue(progress_bar->value() + 1);});
    QObject::connect(dial, &QAbstractSlider::valueChanged, progress_bar, [=](){progress_bar->setValue(dial->value());});
    QObject::connect(slider, &QAbstractSlider::valueChanged, progress_bar, [=](){progress_bar->setValue(slider->value());});
    QObject::connect(radio_button_group, &QButtonGroup::idClicked, progress_bar, [=](){progress_bar->setValue(radio_button_group->checkedId() * 25);});
    QObject::connect(line_text, &QLineEdit::textChanged, progress_bar, [=](){progress_bar->setValue((line_text->text()).size());});
    QObject::connect(time_edit, &QDateTimeEdit::timeChanged, progress_bar,
        [=](){
            float secs_to_curr = (time_edit->time()).msecsSinceStartOfDay();
            float all_secs_to_curr = (QTime::currentTime()).msecsSinceStartOfDay();
            progress_bar->setValue(secs_to_curr / all_secs_to_curr * 100);
        });
    QObject::connect(date_edit, &QDateTimeEdit::dateChanged,
        progress_bar,
        [=](){
            QDate d1(2026, 1, 1);
            QDate d2 = date_edit->date();
            long all_days_to_curr = d1.daysTo(QDate::currentDate());
            long days_to_curr = d1.daysTo(d2);
            progress_bar->setValue(days_to_curr * 100 / all_days_to_curr);
        });
    QObject::connect(check_button_group, &QButtonGroup::buttonToggled,
        progress_bar,
        [=](){
            int count = 0;
            for (auto b : check_button_group->buttons())
                if (b->isChecked()) ++count;

            progress_bar->setValue(count * 25);
        });

    layout->addWidget(tab_widget);
    layout_for_second_widget->addLayout(layout_for_second_widget_top);
    layout_for_second_widget->addLayout(layout_for_second_widget_bottom);
    layout_for_second_widget->addWidget(second_widget_top);
    layout_for_second_widget->addWidget(second_widget_bottom);

    layout_for_second_widget_top->addLayout(layout_line_text);
    layout_for_second_widget_top->addLayout(layout_time_edit);
    layout_for_second_widget_top->addLayout(layout_date_edit);
    layout_line_text->addWidget(label_text);
    layout_line_text->addWidget(line_text);
    layout_time_edit->addWidget(label_time_text);
    layout_time_edit->addWidget(time_edit);
    layout_date_edit->addWidget(label_date_text);
    layout_date_edit->addWidget(date_edit);

    layout_for_second_widget_bottom->addWidget(progress_bar);
    layout_for_second_widget_bottom->addWidget(test_button);
    layout_for_second_widget_bottom->addWidget(dial);
    layout_for_second_widget_bottom->addWidget(slider);
    layout_for_button_widget->addWidget(test_button_2);
    layout_for_second_widget_bottom->addLayout(v_layout_radio_button);
    v_layout_radio_button->addWidget(radio_button_1);
    v_layout_radio_button->addWidget(radio_button_2);
    v_layout_radio_button->addWidget(radio_button_3);
    v_layout_radio_button->addWidget(radio_button_4);
    layout_for_second_widget_bottom->addLayout(v_layout_check_button);
    v_layout_check_button->addWidget(check_button_1);
    v_layout_check_button->addWidget(check_button_2);
    v_layout_check_button->addWidget(check_button_3);
    v_layout_check_button->addWidget(check_button_4);
    main_widget->show();
    return app.exec();
}
