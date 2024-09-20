#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>
#include<QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT  //用 Q_OBJECT 宏来启用 Qt 的信号和槽机制

public:
    // 构造函数
    Calculator(QWidget *parent = nullptr);
    // 析构函数
    ~Calculator();

    //初始化按键字体
    void initFont();

    //将输入的数存入计算式
    void setExperssion();

    // 检查是否可以追加运算符
    bool canAppendOperator();

    // 替换最后一个运算符为新的运算符
    void replaceOperator(QChar newOperator);

    //特殊按键功能设置
    void buttonFunction();

    //转换为后缀表达式
    QString toPostfixExpression(QString str);

    //做运算
    double operation(QString rpn);

   //在QLineEdit框中显示计算式的信号
    signals:
    void showLabel();

private:
    //ui 指针
    Ui::Calculator *ui;

    //用户输入的计算式
    QString expression;

    //检查括号是否匹配
    bool areBracketsBalanced(const QString &expression);

    //计算式显示标签
    QLineEdit *label;
};

#endif // CALCULATOR_H
