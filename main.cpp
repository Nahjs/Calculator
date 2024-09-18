#include "calculator.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    //创建QApplication对象
    QApplication a(argc, argv);
    // 创建Calculator对象
    Calculator w;
    w.show();

    // 进入事件循环
   return a.exec();
}
