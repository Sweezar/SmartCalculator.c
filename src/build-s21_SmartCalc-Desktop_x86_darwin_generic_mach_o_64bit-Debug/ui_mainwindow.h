/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *number_button_4;
    QPushButton *number_button_7;
    QPushButton *number_button_1;
    QPushButton *operation_button_sign;
    QPushButton *operation_button_clear;
    QPushButton *operation_button_remove;
    QPushButton *number_button_8;
    QPushButton *number_button_2;
    QPushButton *number_button_5;
    QPushButton *number_button_0;
    QPushButton *operation_button_dot;
    QPushButton *number_button_9;
    QPushButton *number_button_3;
    QPushButton *number_button_6;
    QPushButton *operation_button_percent;
    QPushButton *operation_button_mult;
    QPushButton *operation_button_sum;
    QPushButton *operation_button_sub;
    QPushButton *operation_button_div;
    QPushButton *operation_button_sin;
    QPushButton *operation_button_lg;
    QPushButton *operation_button_ln;
    QPushButton *operation_button_cos;
    QPushButton *operation_button_tan;
    QPushButton *operation_button_left_bracket;
    QPushButton *operation_button_right_bracket;
    QPushButton *operation_button_atan;
    QPushButton *operation_button_sqrt;
    QPushButton *operation_button_pow;
    QPushButton *operation_button_mod;
    QPushButton *operation_button_asin;
    QPushButton *operation_button_acos;
    QRadioButton *radioButton_default;
    QRadioButton *radioButton_credit;
    QRadioButton *radioButton_deposit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(582, 406);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid grey;\n"
"	border-radius: 10px;\n"
"	font-size: 36px;\n"
"	line-height: 60px;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	color: black;\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 8, 561, 80));
        label->setStyleSheet(QString::fromUtf8("font: 36pt \"PT Sans\";\n"
"color: rgb(10, 10, 10);\n"
"background-color: rgb(250, 250, 250);\n"
"padding: 15px"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        number_button_4 = new QPushButton(centralwidget);
        number_button_4->setObjectName(QString::fromUtf8("number_button_4"));
        number_button_4->setGeometry(QRect(10, 220, 81, 61));
        number_button_7 = new QPushButton(centralwidget);
        number_button_7->setObjectName(QString::fromUtf8("number_button_7"));
        number_button_7->setGeometry(QRect(10, 160, 81, 61));
        number_button_1 = new QPushButton(centralwidget);
        number_button_1->setObjectName(QString::fromUtf8("number_button_1"));
        number_button_1->setGeometry(QRect(10, 280, 81, 61));
        operation_button_sign = new QPushButton(centralwidget);
        operation_button_sign->setObjectName(QString::fromUtf8("operation_button_sign"));
        operation_button_sign->setGeometry(QRect(10, 340, 81, 61));
        operation_button_sign->setStyleSheet(QString::fromUtf8(""));
        operation_button_clear = new QPushButton(centralwidget);
        operation_button_clear->setObjectName(QString::fromUtf8("operation_button_clear"));
        operation_button_clear->setGeometry(QRect(10, 100, 81, 61));
        operation_button_clear->setStyleSheet(QString::fromUtf8(""));
        operation_button_remove = new QPushButton(centralwidget);
        operation_button_remove->setObjectName(QString::fromUtf8("operation_button_remove"));
        operation_button_remove->setGeometry(QRect(90, 100, 81, 61));
        operation_button_remove->setStyleSheet(QString::fromUtf8(""));
        number_button_8 = new QPushButton(centralwidget);
        number_button_8->setObjectName(QString::fromUtf8("number_button_8"));
        number_button_8->setGeometry(QRect(90, 160, 81, 61));
        number_button_2 = new QPushButton(centralwidget);
        number_button_2->setObjectName(QString::fromUtf8("number_button_2"));
        number_button_2->setGeometry(QRect(90, 280, 81, 61));
        number_button_5 = new QPushButton(centralwidget);
        number_button_5->setObjectName(QString::fromUtf8("number_button_5"));
        number_button_5->setGeometry(QRect(90, 220, 81, 61));
        number_button_0 = new QPushButton(centralwidget);
        number_button_0->setObjectName(QString::fromUtf8("number_button_0"));
        number_button_0->setGeometry(QRect(90, 340, 81, 61));
        operation_button_dot = new QPushButton(centralwidget);
        operation_button_dot->setObjectName(QString::fromUtf8("operation_button_dot"));
        operation_button_dot->setGeometry(QRect(170, 340, 81, 61));
        operation_button_dot->setStyleSheet(QString::fromUtf8(""));
        number_button_9 = new QPushButton(centralwidget);
        number_button_9->setObjectName(QString::fromUtf8("number_button_9"));
        number_button_9->setGeometry(QRect(170, 160, 81, 61));
        number_button_3 = new QPushButton(centralwidget);
        number_button_3->setObjectName(QString::fromUtf8("number_button_3"));
        number_button_3->setGeometry(QRect(170, 280, 81, 61));
        number_button_6 = new QPushButton(centralwidget);
        number_button_6->setObjectName(QString::fromUtf8("number_button_6"));
        number_button_6->setGeometry(QRect(170, 220, 81, 61));
        operation_button_percent = new QPushButton(centralwidget);
        operation_button_percent->setObjectName(QString::fromUtf8("operation_button_percent"));
        operation_button_percent->setGeometry(QRect(170, 100, 81, 61));
        operation_button_percent->setStyleSheet(QString::fromUtf8(""));
        operation_button_mult = new QPushButton(centralwidget);
        operation_button_mult->setObjectName(QString::fromUtf8("operation_button_mult"));
        operation_button_mult->setGeometry(QRect(250, 220, 81, 61));
        operation_button_mult->setStyleSheet(QString::fromUtf8(""));
        operation_button_sum = new QPushButton(centralwidget);
        operation_button_sum->setObjectName(QString::fromUtf8("operation_button_sum"));
        operation_button_sum->setGeometry(QRect(250, 340, 81, 61));
        operation_button_sum->setStyleSheet(QString::fromUtf8(""));
        operation_button_sub = new QPushButton(centralwidget);
        operation_button_sub->setObjectName(QString::fromUtf8("operation_button_sub"));
        operation_button_sub->setGeometry(QRect(250, 280, 81, 61));
        operation_button_sub->setStyleSheet(QString::fromUtf8(""));
        operation_button_div = new QPushButton(centralwidget);
        operation_button_div->setObjectName(QString::fromUtf8("operation_button_div"));
        operation_button_div->setGeometry(QRect(250, 160, 81, 61));
        operation_button_div->setStyleSheet(QString::fromUtf8(""));
        operation_button_sin = new QPushButton(centralwidget);
        operation_button_sin->setObjectName(QString::fromUtf8("operation_button_sin"));
        operation_button_sin->setGeometry(QRect(330, 160, 81, 61));
        operation_button_sin->setStyleSheet(QString::fromUtf8(""));
        operation_button_lg = new QPushButton(centralwidget);
        operation_button_lg->setObjectName(QString::fromUtf8("operation_button_lg"));
        operation_button_lg->setGeometry(QRect(490, 100, 81, 61));
        operation_button_lg->setStyleSheet(QString::fromUtf8(""));
        operation_button_ln = new QPushButton(centralwidget);
        operation_button_ln->setObjectName(QString::fromUtf8("operation_button_ln"));
        operation_button_ln->setGeometry(QRect(410, 100, 81, 61));
        operation_button_ln->setStyleSheet(QString::fromUtf8(""));
        operation_button_cos = new QPushButton(centralwidget);
        operation_button_cos->setObjectName(QString::fromUtf8("operation_button_cos"));
        operation_button_cos->setGeometry(QRect(330, 220, 81, 61));
        operation_button_cos->setStyleSheet(QString::fromUtf8(""));
        operation_button_tan = new QPushButton(centralwidget);
        operation_button_tan->setObjectName(QString::fromUtf8("operation_button_tan"));
        operation_button_tan->setGeometry(QRect(330, 280, 81, 61));
        operation_button_tan->setStyleSheet(QString::fromUtf8(""));
        operation_button_left_bracket = new QPushButton(centralwidget);
        operation_button_left_bracket->setObjectName(QString::fromUtf8("operation_button_left_bracket"));
        operation_button_left_bracket->setGeometry(QRect(250, 100, 81, 61));
        operation_button_left_bracket->setStyleSheet(QString::fromUtf8(""));
        operation_button_right_bracket = new QPushButton(centralwidget);
        operation_button_right_bracket->setObjectName(QString::fromUtf8("operation_button_right_bracket"));
        operation_button_right_bracket->setGeometry(QRect(330, 100, 81, 61));
        operation_button_right_bracket->setStyleSheet(QString::fromUtf8(""));
        operation_button_atan = new QPushButton(centralwidget);
        operation_button_atan->setObjectName(QString::fromUtf8("operation_button_atan"));
        operation_button_atan->setGeometry(QRect(410, 280, 81, 61));
        operation_button_atan->setStyleSheet(QString::fromUtf8(""));
        operation_button_sqrt = new QPushButton(centralwidget);
        operation_button_sqrt->setObjectName(QString::fromUtf8("operation_button_sqrt"));
        operation_button_sqrt->setGeometry(QRect(330, 340, 81, 61));
        operation_button_sqrt->setStyleSheet(QString::fromUtf8(""));
        operation_button_pow = new QPushButton(centralwidget);
        operation_button_pow->setObjectName(QString::fromUtf8("operation_button_pow"));
        operation_button_pow->setGeometry(QRect(490, 160, 81, 61));
        operation_button_pow->setStyleSheet(QString::fromUtf8(""));
        operation_button_mod = new QPushButton(centralwidget);
        operation_button_mod->setObjectName(QString::fromUtf8("operation_button_mod"));
        operation_button_mod->setGeometry(QRect(410, 340, 81, 61));
        operation_button_mod->setStyleSheet(QString::fromUtf8(""));
        operation_button_asin = new QPushButton(centralwidget);
        operation_button_asin->setObjectName(QString::fromUtf8("operation_button_asin"));
        operation_button_asin->setGeometry(QRect(410, 160, 81, 61));
        operation_button_asin->setStyleSheet(QString::fromUtf8(""));
        operation_button_acos = new QPushButton(centralwidget);
        operation_button_acos->setObjectName(QString::fromUtf8("operation_button_acos"));
        operation_button_acos->setGeometry(QRect(410, 220, 81, 61));
        operation_button_acos->setStyleSheet(QString::fromUtf8(""));
        radioButton_default = new QRadioButton(centralwidget);
        radioButton_default->setObjectName(QString::fromUtf8("radioButton_default"));
        radioButton_default->setGeometry(QRect(490, 220, 81, 61));
        radioButton_default->setStyleSheet(QString::fromUtf8("padding-left: 5px;\n"
"font-size: 16px;"));
        radioButton_credit = new QRadioButton(centralwidget);
        radioButton_credit->setObjectName(QString::fromUtf8("radioButton_credit"));
        radioButton_credit->setGeometry(QRect(490, 280, 81, 61));
        radioButton_credit->setStyleSheet(QString::fromUtf8("padding-left: 5px;\n"
"font-size: 16px;"));
        radioButton_deposit = new QRadioButton(centralwidget);
        radioButton_deposit->setObjectName(QString::fromUtf8("radioButton_deposit"));
        radioButton_deposit->setGeometry(QRect(490, 340, 81, 61));
        radioButton_deposit->setStyleSheet(QString::fromUtf8("padding-left: 5px;\n"
"font-size: 16px;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        number_button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        number_button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        number_button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        operation_button_sign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        operation_button_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        operation_button_remove->setText(QCoreApplication::translate("MainWindow", "<-x", nullptr));
        number_button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        number_button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        number_button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        number_button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        operation_button_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        number_button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        number_button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        number_button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        operation_button_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        operation_button_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        operation_button_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        operation_button_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        operation_button_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        operation_button_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        operation_button_lg->setText(QCoreApplication::translate("MainWindow", "lg", nullptr));
        operation_button_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        operation_button_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        operation_button_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        operation_button_left_bracket->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        operation_button_right_bracket->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        operation_button_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        operation_button_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        operation_button_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        operation_button_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        operation_button_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        operation_button_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        radioButton_default->setText(QCoreApplication::translate("MainWindow", "default", nullptr));
        radioButton_credit->setText(QCoreApplication::translate("MainWindow", "credit", nullptr));
        radioButton_deposit->setText(QCoreApplication::translate("MainWindow", "deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
