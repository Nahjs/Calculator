#include "calculator.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();

   return a.exec();
}
