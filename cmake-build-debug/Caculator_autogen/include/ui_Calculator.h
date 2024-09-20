/********************************************************************************
** Form generated from reading UI file 'Calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_6;
    QPushButton *btn_5;
    QPushButton *btn_4;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_point;
    QPushButton *btn_0;
    QPushButton *btn_result;
    QPushButton *btn_add;
    QPushButton *btn_sub;
    QPushButton *btn_multi;
    QPushButton *btn_div;
    QPushButton *btn_del;
    QPushButton *btn_clear;
    QPushButton *btn_mod;
    QPushButton *btn_leftBrackets;
    QPushButton *btn_rightBrackets;
    QLineEdit *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName("Calculator");
        Calculator->resize(330, 510);
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName("centralwidget");
        btn_7 = new QPushButton(centralwidget);
        btn_7->setObjectName("btn_7");
        btn_7->setGeometry(QRect(30, 219, 61, 61));
        btn_8 = new QPushButton(centralwidget);
        btn_8->setObjectName("btn_8");
        btn_8->setGeometry(QRect(100, 219, 61, 61));
        btn_9 = new QPushButton(centralwidget);
        btn_9->setObjectName("btn_9");
        btn_9->setGeometry(QRect(170, 219, 61, 61));
        btn_6 = new QPushButton(centralwidget);
        btn_6->setObjectName("btn_6");
        btn_6->setGeometry(QRect(170, 289, 61, 61));
        btn_5 = new QPushButton(centralwidget);
        btn_5->setObjectName("btn_5");
        btn_5->setGeometry(QRect(100, 289, 61, 61));
        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName("btn_4");
        btn_4->setGeometry(QRect(30, 290, 61, 61));
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName("btn_1");
        btn_1->setGeometry(QRect(30, 360, 61, 61));
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName("btn_2");
        btn_2->setGeometry(QRect(100, 360, 61, 61));
        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName("btn_3");
        btn_3->setGeometry(QRect(170, 360, 61, 61));
        btn_point = new QPushButton(centralwidget);
        btn_point->setObjectName("btn_point");
        btn_point->setGeometry(QRect(170, 430, 61, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font.setPointSize(9);
        font.setBold(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        btn_point->setFont(font);
        btn_0 = new QPushButton(centralwidget);
        btn_0->setObjectName("btn_0");
        btn_0->setGeometry(QRect(100, 430, 61, 61));
        btn_result = new QPushButton(centralwidget);
        btn_result->setObjectName("btn_result");
        btn_result->setGeometry(QRect(240, 429, 61, 61));
        btn_add = new QPushButton(centralwidget);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(240, 360, 61, 61));
        btn_sub = new QPushButton(centralwidget);
        btn_sub->setObjectName("btn_sub");
        btn_sub->setGeometry(QRect(240, 289, 61, 61));
        btn_multi = new QPushButton(centralwidget);
        btn_multi->setObjectName("btn_multi");
        btn_multi->setGeometry(QRect(240, 219, 61, 61));
        btn_div = new QPushButton(centralwidget);
        btn_div->setObjectName("btn_div");
        btn_div->setGeometry(QRect(240, 149, 61, 61));
        btn_del = new QPushButton(centralwidget);
        btn_del->setObjectName("btn_del");
        btn_del->setGeometry(QRect(100, 149, 61, 61));
        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName("btn_clear");
        btn_clear->setGeometry(QRect(30, 149, 61, 61));
        btn_mod = new QPushButton(centralwidget);
        btn_mod->setObjectName("btn_mod");
        btn_mod->setGeometry(QRect(30, 429, 61, 61));
        btn_leftBrackets = new QPushButton(centralwidget);
        btn_leftBrackets->setObjectName("btn_leftBrackets");
        btn_leftBrackets->setGeometry(QRect(170, 150, 31, 61));
        btn_rightBrackets = new QPushButton(centralwidget);
        btn_rightBrackets->setObjectName("btn_rightBrackets");
        btn_rightBrackets->setGeometry(QRect(200, 150, 31, 61));
        label = new QLineEdit(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 271, 121));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 10, 271, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Calculator->setCentralWidget(centralwidget);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "\350\256\241\347\256\227\345\231\250", nullptr));
        btn_7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
#if QT_CONFIG(shortcut)
        btn_7->setShortcut(QCoreApplication::translate("Calculator", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
#if QT_CONFIG(shortcut)
        btn_8->setShortcut(QCoreApplication::translate("Calculator", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
#if QT_CONFIG(shortcut)
        btn_9->setShortcut(QCoreApplication::translate("Calculator", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
#if QT_CONFIG(shortcut)
        btn_6->setShortcut(QCoreApplication::translate("Calculator", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
#if QT_CONFIG(shortcut)
        btn_5->setShortcut(QCoreApplication::translate("Calculator", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
#if QT_CONFIG(shortcut)
        btn_4->setShortcut(QCoreApplication::translate("Calculator", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
#if QT_CONFIG(shortcut)
        btn_1->setShortcut(QCoreApplication::translate("Calculator", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
#if QT_CONFIG(shortcut)
        btn_2->setShortcut(QCoreApplication::translate("Calculator", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
#if QT_CONFIG(shortcut)
        btn_3->setShortcut(QCoreApplication::translate("Calculator", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_point->setText(QCoreApplication::translate("Calculator", ".", nullptr));
#if QT_CONFIG(shortcut)
        btn_point->setShortcut(QCoreApplication::translate("Calculator", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
#if QT_CONFIG(shortcut)
        btn_0->setShortcut(QCoreApplication::translate("Calculator", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_result->setText(QCoreApplication::translate("Calculator", "\357\274\235", nullptr));
#if QT_CONFIG(shortcut)
        btn_result->setShortcut(QCoreApplication::translate("Calculator", "=", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_add->setText(QCoreApplication::translate("Calculator", "\342\236\225", nullptr));
#if QT_CONFIG(shortcut)
        btn_add->setShortcut(QCoreApplication::translate("Calculator", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_sub->setText(QCoreApplication::translate("Calculator", "\342\236\226", nullptr));
#if QT_CONFIG(shortcut)
        btn_sub->setShortcut(QCoreApplication::translate("Calculator", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_multi->setText(QCoreApplication::translate("Calculator", "\342\234\226", nullptr));
#if QT_CONFIG(shortcut)
        btn_multi->setShortcut(QCoreApplication::translate("Calculator", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_div->setText(QCoreApplication::translate("Calculator", "\342\236\227", nullptr));
#if QT_CONFIG(shortcut)
        btn_div->setShortcut(QCoreApplication::translate("Calculator", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_del->setText(QCoreApplication::translate("Calculator", "\360\237\224\231", nullptr));
#if QT_CONFIG(shortcut)
        btn_del->setShortcut(QCoreApplication::translate("Calculator", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_clear->setText(QCoreApplication::translate("Calculator", "AC", nullptr));
#if QT_CONFIG(shortcut)
        btn_clear->setShortcut(QCoreApplication::translate("Calculator", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_mod->setText(QCoreApplication::translate("Calculator", "%", nullptr));
#if QT_CONFIG(shortcut)
        btn_mod->setShortcut(QCoreApplication::translate("Calculator", "%", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_leftBrackets->setText(QCoreApplication::translate("Calculator", "(", nullptr));
#if QT_CONFIG(shortcut)
        btn_leftBrackets->setShortcut(QCoreApplication::translate("Calculator", "(", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_rightBrackets->setText(QCoreApplication::translate("Calculator", ")", nullptr));
#if QT_CONFIG(shortcut)
        btn_rightBrackets->setShortcut(QCoreApplication::translate("Calculator", ")", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
