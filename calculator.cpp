#include "calculator.h"
#include "ui_Calculator.h"
#include <QLineEdit>
#include <QPushButton>
#include<QStack>
#include<QDebug>
#include<cmath>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

// 构造函数
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    //设置窗口标题
    this->setWindowTitle("计算器");

    // 初始化 QLineEdit
    label = new QLineEdit(this);
    label->setReadOnly(true);
    label->setAlignment(Qt::AlignRight);
    label->setStyleSheet("font-size:20pt; background: transparent; border: none;");

    // 将 QLineEdit 添加到布局中
    ui->verticalLayout->addWidget(label);


    //设置表达式
    setExperssion();
    //初始化按键
    initFont();
    //按键功能
    buttonFunction();

    // 在 QLineEdit 中显示表达式
    connect(this, &Calculator::showLabel, this, [=]() {
        label->setText(expression);
    });
}

//析构函数
Calculator::~Calculator()
{
    delete ui;
}

//初始化字体
void Calculator::initFont()
{
    ui->btn_0->setStyleSheet("font-size:20pt");
    ui->btn_1->setStyleSheet("font-size:20pt");
    ui->btn_2->setStyleSheet("font-size:20pt");
    ui->btn_3->setStyleSheet("font-size:20pt");
    ui->btn_4->setStyleSheet("font-size:20pt");
    ui->btn_5->setStyleSheet("font-size:20pt");
    ui->btn_6->setStyleSheet("font-size:20pt");
    ui->btn_7->setStyleSheet("font-size:20pt");
    ui->btn_8->setStyleSheet("font-size:20pt");
    ui->btn_9->setStyleSheet("font-size:20pt");
    ui->btn_point->setStyleSheet("font-size:20pt");
    ui->btn_mod->setStyleSheet("font-size:20pt");
    ui->btn_clear->setStyleSheet("font-size:20pt");
    ui->btn_del->setStyleSheet("font-size:20pt");
    ui->btn_leftBrackets->setStyleSheet("font-size:20pt");
    ui->btn_rightBrackets->setStyleSheet("font-size:20pt");
    ui->btn_add->setStyleSheet("font-size:20pt");
    ui->btn_sub->setStyleSheet("font-size:20pt");
    ui->btn_multi->setStyleSheet("font-size:20pt");
    ui->btn_div->setStyleSheet("font-size:20pt");
    ui->btn_result->setStyleSheet("font-size:20pt");
    ui->label->setStyleSheet("font-size:20pt; color: red;");
}

//将按键值存入表达式
void Calculator::setExperssion() {


    // 数字按钮的点击事件
    auto appendDigit = [=](QChar digit) {
        if (expression.isEmpty() || expression.back() != ')') {
            expression += digit;
            ui->label->clear(); // 清除错误信息
            emit showLabel();
        }
    };

    connect(ui->btn_0, &QPushButton::clicked, this, [=](){ appendDigit('0'); });
    connect(ui->btn_1, &QPushButton::clicked, this, [=](){ appendDigit('1'); });
    connect(ui->btn_2, &QPushButton::clicked, this, [=](){ appendDigit('2'); });
    connect(ui->btn_3, &QPushButton::clicked, this, [=](){ appendDigit('3'); });
    connect(ui->btn_4, &QPushButton::clicked, this, [=](){ appendDigit('4'); });
    connect(ui->btn_5, &QPushButton::clicked, this, [=](){ appendDigit('5'); });
    connect(ui->btn_6, &QPushButton::clicked, this, [=](){ appendDigit('6'); });
    connect(ui->btn_7, &QPushButton::clicked, this, [=](){ appendDigit('7'); });
    connect(ui->btn_8, &QPushButton::clicked, this, [=](){ appendDigit('8'); });
    connect(ui->btn_9, &QPushButton::clicked, this, [=](){ appendDigit('9'); });


    // 小数点按钮的点击事件
    connect(ui->btn_point, &QPushButton::clicked, this, [=](){
        if (expression.isEmpty() || expression.back() == ')' || expression.back() == '('|| expression.back() == '.'
            || expression.back() == '+'|| expression.back() == '-'|| expression.back() == '*'|| expression.back() == '/'|| expression.back() == '%') {
            return;//封掉小数点键
        }

        // 查找最后一个运算符的位置
        int lastOperatorIndex = expression.lastIndexOf(QRegularExpression("[+\\-*/%()]"));
        //从最后一个运算符的位置开始，获取当前数字部分的子字符串
        QString currentNumber = expression.mid(lastOperatorIndex + 1);
        //检查当前数字部分是否已经包含小数点
        if (currentNumber.contains('.')) {
            return;
        }

        expression += '.';
        emit showLabel();
    });


    // 运算符按钮的点击事件
    auto appendOperator = [=](QChar op) {
        if (canAppendOperator()) {
            replaceOperator(op);
        }
    };

    connect(ui->btn_add, &QPushButton::clicked, this, [=](){ appendOperator('+'); });
    connect(ui->btn_sub, &QPushButton::clicked, this, [=](){ appendOperator('-'); });
    connect(ui->btn_multi, &QPushButton::clicked, this, [=](){ appendOperator('*'); });
    connect(ui->btn_div, &QPushButton::clicked, this, [=](){ appendOperator('/'); });
    connect(ui->btn_mod, &QPushButton::clicked, this, [=](){ appendOperator('%'); });

    // 左括号按钮的点击事件
    connect(ui->btn_leftBrackets, &QPushButton::clicked, this, [=](){
        if ( expression.isEmpty() || (!expression.back().isDigit() && expression.back() != '.' && expression.back() != ')')) {
            expression += '(';
            ui->label->clear(); // 清除错误信息
            emit showLabel();
        }
    });

    // 右括号按钮的点击事件
    connect(ui->btn_rightBrackets, &QPushButton::clicked, this, [=](){
        if (!expression.isEmpty() && expression.back() != '('&& expression.back() != '.') {
             expression += ')';
             emit showLabel();
         }
    });
}

// 检查是否可以追加运算符
bool Calculator::canAppendOperator() {
        if (expression.isEmpty()) {
            return false;
        }
        QChar lastChar = expression.back();
        // 如果最后一个字符是数字或右括号，可以追加运算符
    return lastChar.isDigit() || lastChar == ')' || lastChar == '+' || lastChar == '-' ||
       lastChar == '*' || lastChar == '/' || lastChar == '%';
}

// 替换最后一个运算符为新的运算符
void Calculator::replaceOperator(QChar newOperator) {
        if (expression.length() >1 && (expression.back() == '+' || expression.back() == '-' ||
                                           expression.back() == '*' || expression.back() == '/' || expression.back() == '%')) {
            expression = expression.left(expression.length() - 1) + newOperator;
                                           } else {
                                               expression += newOperator;
                                           }
        emit showLabel();
    }

//特殊按键功能实现
void Calculator::buttonFunction() {
    //删除键
    connect(ui->btn_del, &QPushButton::clicked, this, [=]() {
        if (!expression.isEmpty()) {
            expression.chop(1); //删除字符串最后一位元素
        }
        emit showLabel();
    });

    //清空键（重新启用所有按键）
    connect(ui->btn_clear, &QPushButton::clicked, this, [=](){
        expression.clear();
        emit showLabel();
        ui->btn_add->setEnabled(true);
        ui->btn_sub->setEnabled(true);
        ui->btn_multi->setEnabled(true);
        ui->btn_div->setEnabled(true);
        ui->btn_leftBrackets->setEnabled(true);
        ui->btn_rightBrackets->setEnabled(true);
    });

    //等于键
    connect(ui->btn_result, &QPushButton::clicked, this, [=]() {
        if (areBracketsBalanced(expression)) {//检查表达式中的括号是否匹配
            label->setText(QString::number(Calculator::operation(toPostfixExpression(expression))));
 } else {
     label->setText("Error");
 }
    });
}

//转换为后缀表达式
QString Calculator::toPostfixExpression(QString str)
{
    QString s;//存储后缀表达式的字符串
    QStack<QChar> opStack; //存操作符的栈

    for(auto i : str){
        //数字或小数点直接存入字符串
        if((i <= '9' && i >= '0') || i == '.'){
            s += i;
        }
        //左括号直接入栈
        if(i == '('){
            opStack.push(i);
        }
        //遇到右括号，出栈栈顶元素直到栈顶元素为左括号
        if(i == ')'){
            while(opStack.top() != '('){
                s += ' ';
                s += opStack.pop();
            }
            opStack.pop();//将左括号出栈
        }
        //运算符优先级不低于栈顶元素则入栈，否则出栈栈顶元素后入栈
        if(i == '+'||i == '-'){
            s += ' ';
                while(!opStack.empty() && opStack.top() != '(' && opStack.top() != '+' && opStack.top() != '-'){
                    s += opStack.pop();
                    s += ' ';
                }
                opStack.push(i);
            }
        if(i == '*'||i == '/'||i == '%'){
                s += ' ';
                opStack.push(i);
            }
    }
    //出栈所有元素
    while(!opStack.empty()){
        s += ' ';
        s += opStack.pop();
    }
    qDebug() << str << s;
    return s;
}

//使用栈来检查括号匹配
bool Calculator::areBracketsBalanced(const QString &expression) {

    QStack<QChar> bracketStack;//用于存储左括号的栈

    //用于定义匹配的括号对
    QMap<QChar, QChar> matchingBrackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (QChar ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            bracketStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (bracketStack.isEmpty() || bracketStack.top() != matchingBrackets[ch]) {
                return false;
            }
            bracketStack.pop();
        }
    }

    return bracketStack.isEmpty();//最终检查
}

//计算后缀表达式的值
double Calculator::operation(QString rpn)
{
    QStack<double> result;//用于存储操作数的栈
    QString num;//用于构建多位数或小数

    //遍历后缀表达式
    for(auto i : rpn){
        if((i >= '0' && i <= '9') || i == '.' || i == ' '){
            if((i >= '0' && i <= '9') || i == '.' ){
                num += i;
            }
            if(i == ' '){
                if(!num.isEmpty() && num.at(0) >= '0' && num.at(0) <= '9'){
                    result.push(num.toDouble());
                    //当遇到空格时，表示一个完整的数字已经结束，
                    //将 num 转换为 double 并压入栈中，然后清空 num 以便处理下一个数字或运算符。
                    num.clear();
                }
            }
        }
        //加法
        if(i == '+'){
            if(result.size() < 2) {
                ui->label->setText("Error");
                return 0;
            }
            double temp1 = result.pop();
            double temp2 = result.pop();
            result.push(temp2+temp1);
        }
        //减法
        if(i == '-'){
            if(result.size() < 2) {
                ui->label->setText("Error");
                return 0;
            }
            double temp1 = result.pop();
            double temp2 = result.pop();
            result.push(temp2-temp1);
        }
        //乘法
        if(i == '*'){
            if(result.size() < 2) {
                ui->label->setText("Error");
                return 0;
            }
            double temp1 = result.pop();
            double temp2 = result.pop();
            result.push(temp2*temp1);
        }
        //除法
        if(i == '/'){
            if(result.size() < 2) {
                ui->label->setText("Error");
                return 0;
            }
            double temp1 = result.pop();
            double temp2 = result.pop();
            if (temp1 == 0) {
                ui->label->setText("Error");
            }
            result.push(temp2/temp1);
        }
        //模运算
        if(i == '%'){
            if(result.size() < 2) {
                ui->label->setText("Error");
                return 0;
            }
            double temp1 = result.pop();
            double temp2 = result.pop();
            result.push(fmod(temp2,temp1));
        }
    }
    // 检查是否有多余的操作符
    if(result.size() != 1) {
        label->setText("Error");
        return 0;
    }

    return result.top();
}



