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
    Q_OBJECT

public:
    // 构造函数
    Calculator(QWidget *parent = nullptr);
    // 析构函数
    ~Calculator();

    //初始化按键字体和颜色
    void initButtonStyle();

    //将输入的数存入字符串
    void setExperssion();

    // 检查是否可以追加运算符
    bool canAppendOperator();

    // 替换最后一个运算符为新的运算符
    void replaceOperator(QChar newOperator);

    //特殊按键功能设置
    void buttonFunction();

    //转换为后缀表达式
    QString toRPN(QString str);

    //做运算
    double operation(QString rpn);

signals:
    //显示在QLineEdit框中
    void showLabel();

private:
    Ui::Calculator *ui;

    //用户输入的表达式
    QString m_expression;

    //检查括号是否匹配
    bool areBracketsBalanced(const QString &expression);

    //
    QLineEdit *label;
};

#endif // CALCULATOR_H
