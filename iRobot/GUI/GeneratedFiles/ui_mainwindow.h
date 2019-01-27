/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_colonies;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_current_colony;
    QSpacerItem *horizontal_spacer;
    QPushButton *pushbutton_change_colony;
    QWidget *widget_map_and_controls;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_map_and_bars;
    QGridLayout *gridLayout;
    QScrollBar *horizontal_scrollbar_map;
    QLabel *label_map;
    QScrollBar *vertical_scrollbar_map;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_programming;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_programming;
    QWidget *widget_programming_controls;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_programming_left;
    QGridLayout *gridLayout_3;
    QPushButton *pushbutton_stay;
    QPushButton *pushbutton_go_up;
    QPushButton *pushbutton_go_down;
    QPushButton *pushbutton_delete;
    QPushButton *pushbutton_go_left;
    QPushButton *pushbutton_go_right;
    QWidget *widget_programming_moves;
    QVBoxLayout *verticalLayout_2;
    QComboBox *combobox_last_moves;
    QTextEdit *textedit_current_move_order;
    QWidget *widget_mission_control;
    QGridLayout *gridLayout_2;
    QPushButton *pushbutton_pause_mission;
    QPushButton *pushbutton_start_mission;
    QPushButton *pushbutton_automatic;
    QPushButton *pushbutton_single_step;
    QPushButton *pushbutton_abort_mission;
    QLabel *label_mission_control;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(688, 513);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(252, 175, 62, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 227, 186, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(253, 201, 124, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(126, 87, 31, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(168, 117, 41, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(253, 215, 158, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_colonies = new QWidget(centralWidget);
        widget_colonies->setObjectName(QString::fromUtf8("widget_colonies"));
        horizontalLayout_3 = new QHBoxLayout(widget_colonies);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_current_colony = new QLabel(widget_colonies);
        label_current_colony->setObjectName(QString::fromUtf8("label_current_colony"));

        horizontalLayout_3->addWidget(label_current_colony);

        horizontal_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontal_spacer);

        pushbutton_change_colony = new QPushButton(widget_colonies);
        pushbutton_change_colony->setObjectName(QString::fromUtf8("pushbutton_change_colony"));

        horizontalLayout_3->addWidget(pushbutton_change_colony);


        verticalLayout_3->addWidget(widget_colonies);

        widget_map_and_controls = new QWidget(centralWidget);
        widget_map_and_controls->setObjectName(QString::fromUtf8("widget_map_and_controls"));
        horizontalLayout = new QHBoxLayout(widget_map_and_controls);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_map_and_bars = new QWidget(widget_map_and_controls);
        widget_map_and_bars->setObjectName(QString::fromUtf8("widget_map_and_bars"));
        gridLayout = new QGridLayout(widget_map_and_bars);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontal_scrollbar_map = new QScrollBar(widget_map_and_bars);
        horizontal_scrollbar_map->setObjectName(QString::fromUtf8("horizontal_scrollbar_map"));
        horizontal_scrollbar_map->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontal_scrollbar_map, 1, 0, 1, 1);

        label_map = new QLabel(widget_map_and_bars);
        label_map->setObjectName(QString::fromUtf8("label_map"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush10(QColor(233, 185, 110, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        label_map->setPalette(palette1);
        label_map->setAutoFillBackground(true);
        label_map->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_map, 0, 0, 1, 1);

        vertical_scrollbar_map = new QScrollBar(widget_map_and_bars);
        vertical_scrollbar_map->setObjectName(QString::fromUtf8("vertical_scrollbar_map"));
        vertical_scrollbar_map->setOrientation(Qt::Vertical);

        gridLayout->addWidget(vertical_scrollbar_map, 0, 2, 1, 1);


        horizontalLayout->addWidget(widget_map_and_bars);

        widget = new QWidget(widget_map_and_controls);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(300, 400));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_programming = new QWidget(widget);
        widget_programming->setObjectName(QString::fromUtf8("widget_programming"));
        QPalette palette2;
        QBrush brush11(QColor(46, 52, 54, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        QBrush brush12(QColor(103, 46, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        widget_programming->setPalette(palette2);
        widget_programming->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(widget_programming);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_programming = new QLabel(widget_programming);
        label_programming->setObjectName(QString::fromUtf8("label_programming"));
        label_programming->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_programming);

        widget_programming_controls = new QWidget(widget_programming);
        widget_programming_controls->setObjectName(QString::fromUtf8("widget_programming_controls"));
        widget_programming_controls->setAutoFillBackground(false);
        horizontalLayout_2 = new QHBoxLayout(widget_programming_controls);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_programming_left = new QWidget(widget_programming_controls);
        widget_programming_left->setObjectName(QString::fromUtf8("widget_programming_left"));
        gridLayout_3 = new QGridLayout(widget_programming_left);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushbutton_stay = new QPushButton(widget_programming_left);
        pushbutton_stay->setObjectName(QString::fromUtf8("pushbutton_stay"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushbutton_stay->sizePolicy().hasHeightForWidth());
        pushbutton_stay->setSizePolicy(sizePolicy);
        pushbutton_stay->setMinimumSize(QSize(20, 20));
        pushbutton_stay->setMaximumSize(QSize(30, 30));

        gridLayout_3->addWidget(pushbutton_stay, 3, 1, 1, 1);

        pushbutton_go_up = new QPushButton(widget_programming_left);
        pushbutton_go_up->setObjectName(QString::fromUtf8("pushbutton_go_up"));
        sizePolicy.setHeightForWidth(pushbutton_go_up->sizePolicy().hasHeightForWidth());
        pushbutton_go_up->setSizePolicy(sizePolicy);
        pushbutton_go_up->setMinimumSize(QSize(20, 20));
        pushbutton_go_up->setMaximumSize(QSize(30, 30));

        gridLayout_3->addWidget(pushbutton_go_up, 2, 1, 1, 1);

        pushbutton_go_down = new QPushButton(widget_programming_left);
        pushbutton_go_down->setObjectName(QString::fromUtf8("pushbutton_go_down"));
        sizePolicy.setHeightForWidth(pushbutton_go_down->sizePolicy().hasHeightForWidth());
        pushbutton_go_down->setSizePolicy(sizePolicy);
        pushbutton_go_down->setMinimumSize(QSize(20, 20));
        pushbutton_go_down->setMaximumSize(QSize(30, 30));

        gridLayout_3->addWidget(pushbutton_go_down, 4, 1, 1, 1);

        pushbutton_delete = new QPushButton(widget_programming_left);
        pushbutton_delete->setObjectName(QString::fromUtf8("pushbutton_delete"));
        sizePolicy.setHeightForWidth(pushbutton_delete->sizePolicy().hasHeightForWidth());
        pushbutton_delete->setSizePolicy(sizePolicy);
        pushbutton_delete->setMinimumSize(QSize(20, 20));
        pushbutton_delete->setMaximumSize(QSize(30, 30));

        gridLayout_3->addWidget(pushbutton_delete, 2, 2, 1, 1);

        pushbutton_go_left = new QPushButton(widget_programming_left);
        pushbutton_go_left->setObjectName(QString::fromUtf8("pushbutton_go_left"));
        sizePolicy.setHeightForWidth(pushbutton_go_left->sizePolicy().hasHeightForWidth());
        pushbutton_go_left->setSizePolicy(sizePolicy);
        pushbutton_go_left->setMinimumSize(QSize(20, 20));
        pushbutton_go_left->setMaximumSize(QSize(30, 30));

        gridLayout_3->addWidget(pushbutton_go_left, 3, 0, 1, 1);

        pushbutton_go_right = new QPushButton(widget_programming_left);
        pushbutton_go_right->setObjectName(QString::fromUtf8("pushbutton_go_right"));
        sizePolicy.setHeightForWidth(pushbutton_go_right->sizePolicy().hasHeightForWidth());
        pushbutton_go_right->setSizePolicy(sizePolicy);
        pushbutton_go_right->setMinimumSize(QSize(20, 20));
        pushbutton_go_right->setMaximumSize(QSize(30, 30));

        gridLayout_3->addWidget(pushbutton_go_right, 3, 2, 1, 1);


        horizontalLayout_2->addWidget(widget_programming_left);

        widget_programming_moves = new QWidget(widget_programming_controls);
        widget_programming_moves->setObjectName(QString::fromUtf8("widget_programming_moves"));
        verticalLayout_2 = new QVBoxLayout(widget_programming_moves);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        combobox_last_moves = new QComboBox(widget_programming_moves);
        combobox_last_moves->addItem(QString());
        combobox_last_moves->addItem(QString());
        combobox_last_moves->addItem(QString());
        combobox_last_moves->addItem(QString());
        combobox_last_moves->setObjectName(QString::fromUtf8("combobox_last_moves"));

        verticalLayout_2->addWidget(combobox_last_moves);

        textedit_current_move_order = new QTextEdit(widget_programming_moves);
        textedit_current_move_order->setObjectName(QString::fromUtf8("textedit_current_move_order"));
        textedit_current_move_order->setMaximumSize(QSize(16777215, 35));
        textedit_current_move_order->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textedit_current_move_order->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textedit_current_move_order->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textedit_current_move_order->setLineWrapMode(QTextEdit::NoWrap);
        textedit_current_move_order->setReadOnly(true);

        verticalLayout_2->addWidget(textedit_current_move_order);


        horizontalLayout_2->addWidget(widget_programming_moves);


        verticalLayout_5->addWidget(widget_programming_controls);


        verticalLayout->addWidget(widget_programming);

        widget_mission_control = new QWidget(widget);
        widget_mission_control->setObjectName(QString::fromUtf8("widget_mission_control"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        widget_mission_control->setPalette(palette3);
        widget_mission_control->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(widget_mission_control);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushbutton_pause_mission = new QPushButton(widget_mission_control);
        pushbutton_pause_mission->setObjectName(QString::fromUtf8("pushbutton_pause_mission"));

        gridLayout_2->addWidget(pushbutton_pause_mission, 4, 1, 1, 1);

        pushbutton_start_mission = new QPushButton(widget_mission_control);
        pushbutton_start_mission->setObjectName(QString::fromUtf8("pushbutton_start_mission"));

        gridLayout_2->addWidget(pushbutton_start_mission, 2, 0, 1, 1);

        pushbutton_automatic = new QPushButton(widget_mission_control);
        pushbutton_automatic->setObjectName(QString::fromUtf8("pushbutton_automatic"));

        gridLayout_2->addWidget(pushbutton_automatic, 3, 1, 1, 1);

        pushbutton_single_step = new QPushButton(widget_mission_control);
        pushbutton_single_step->setObjectName(QString::fromUtf8("pushbutton_single_step"));

        gridLayout_2->addWidget(pushbutton_single_step, 3, 0, 1, 1);

        pushbutton_abort_mission = new QPushButton(widget_mission_control);
        pushbutton_abort_mission->setObjectName(QString::fromUtf8("pushbutton_abort_mission"));

        gridLayout_2->addWidget(pushbutton_abort_mission, 2, 1, 1, 1);

        label_mission_control = new QLabel(widget_mission_control);
        label_mission_control->setObjectName(QString::fromUtf8("label_mission_control"));
        label_mission_control->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_mission_control, 1, 0, 1, 2);


        verticalLayout->addWidget(widget_mission_control);


        horizontalLayout->addWidget(widget);


        verticalLayout_3->addWidget(widget_map_and_controls);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 21));
        menuBar->setNativeMenuBar(false);
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);
        QObject::connect(combobox_last_moves, SIGNAL(currentIndexChanged(int)), textedit_current_move_order, SLOT(paste()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Patchbot - The Game", nullptr));
        label_current_colony->setText(QApplication::translate("MainWindow", "Aktuelle Kolonie:", nullptr));
        pushbutton_change_colony->setText(QApplication::translate("MainWindow", "Andere Kolonien", nullptr));
        label_map->setText(QApplication::translate("MainWindow", "Umgebungskarte", nullptr));
        label_programming->setText(QApplication::translate("MainWindow", "Programmieren", nullptr));
        pushbutton_stay->setText(QApplication::translate("MainWindow", "\342\232\253", nullptr));
        pushbutton_go_up->setText(QApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushbutton_go_down->setText(QApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushbutton_delete->setText(QApplication::translate("MainWindow", "\342\217\264", nullptr));
        pushbutton_go_left->setText(QApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushbutton_go_right->setText(QApplication::translate("MainWindow", "\342\206\222", nullptr));
        combobox_last_moves->setItemText(0, QApplication::translate("MainWindow", "Item 1", nullptr));
        combobox_last_moves->setItemText(1, QApplication::translate("MainWindow", "Item 2", nullptr));
        combobox_last_moves->setItemText(2, QApplication::translate("MainWindow", "Item 3", nullptr));
        combobox_last_moves->setItemText(3, QApplication::translate("MainWindow", "Item 4", nullptr));

        pushbutton_pause_mission->setText(QApplication::translate("MainWindow", "Anhalten", nullptr));
        pushbutton_start_mission->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushbutton_automatic->setText(QApplication::translate("MainWindow", "Automatik", nullptr));
        pushbutton_single_step->setText(QApplication::translate("MainWindow", "Einzelschritt", nullptr));
        pushbutton_abort_mission->setText(QApplication::translate("MainWindow", "Abbruch", nullptr));
        label_mission_control->setText(QApplication::translate("MainWindow", "Missionsablauf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
