#include<iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

vector<string> Res;    // 存储输入的表达式
stack<double> Numk;       // 存储操作数的栈
stack<char> Symbolk;   // 存储运算符的栈
stack<double> TempNum;    // 临时存储操作数的栈
stack<char> TempSymbol;    // 临时存储运算符的栈

//判断表达式是否合理
bool isExpressionValid(const std::string& expression) {
    std::stack<char> parenthesesStack;

    for (char c : expression) {
        if (c == '(') {      //判断括号
            parenthesesStack.push(c);
        } else if (c == ')') {
            if (parenthesesStack.empty() || parenthesesStack.top() != '(') {
                std::cout << "Invalid expression: Unmatched closing parenthesis ')'." << std::endl;
                return false;
            }
            parenthesesStack.pop();
        }
    }

    if (!parenthesesStack.empty()) {
        std::cout << "Invalid expression: Unmatched opening parenthesis '('." << std::endl;
        return false;
    }

    std::string operators = "+-*/%";
    for (size_t i = 0; i < expression.length(); i++) {
        if (operators.find(expression[i]) != std::string::npos) {
            if (i == 0 || i == expression.length() - 1 || operators.find(expression[i + 1]) != std::string::npos) {
                std::cout << "Invalid expression: Invalid operator usage." << std::endl;
                return false;
            }
        }else if(expression[i]=='.'||isdigit(expression[i])){
            continue;
        }else{
            cout<<"非法字符"<<endl;
            return false;
        }
    }

    return true;
}


// 加载栈并计算结果
double Load_Stack(string std, stack<double>& Num, stack<char>& Symbol) {
    int i = 0;
    char k;
    int len = std.length();
    while (i < len) {
        k = std[i++];
        if (('0' <= k && k <= '9') || k == '.') {    // 如果是数字字符或小数点
            string numStr;
            if(i==len){
                numStr+=k;
            }
            while ((('0' <= k && k <= '9') || k == '.') && i < len) {    // 处理数字和小数点
                numStr += k;
                k = std[i++];
                if(i==len)
                    numStr+=k;
            }
            if(i!=len){
                i--;
            }
            double num = stod(numStr);    // 将字符串转换为浮点数
            Num.push(num);    // 将数字压入操作数栈
        } else {    // 如果是运算符字符
            switch (k) {
                case '+':
                case '-':
                    Symbol.push(k);    // 将运算符压入运算符栈
                    break;
                case '*':
                    k = std[i++];
                    if (('0' <= k && k <= '9') || k == '.') {
                        string numStr;
                        if(i==len){
                            numStr+=k;
                        }
                        while ((('0' <= k && k <= '9') || k == '.') && i < len) {
                            numStr += k;
                            k = std[i++];
                            if(i==len)
                                numStr+=k;
                        }
                        if(i!=len){
                            i--;
                        }
                        double num = stod(numStr);    // 将字符串转换为浮点数
                        double temp = Num.top() * num;    // 计算乘法结果
                        Num.pop();
                        Num.push(temp);
                    } else if (k == '(') {
                        string op;
                        while (1) {
                            char stTemp = std[i++];
                            if (stTemp == ')') {
                                break;
                            }
                            op += stTemp;
                        }
                        double temp = Load_Stack(op, TempNum, TempSymbol);    // 递归计算括号内的表达式结果
                        temp *= Num.top();    // 计算乘法结果
                        stack<double>().swap(TempNum);    // 清空临时操作数栈
                        stack<char>().swap(TempSymbol);    // 清空临时运算符栈
                        Num.pop();
                        Num.push(temp);
                    }
                    break;
                case '/':
                    k = std[i++];
                    if (('0' <= k && k <= '9') || k == '.') {
                        string numStr;
                        if(i==len){
                            numStr+=k;
                        }
                        while ((('0' <= k && k <= '9') || k == '.') && i < len) {
                            numStr += k;
                            k = std[i++];
                            if(i==len)
                                numStr+=k;
                        }
                        if(i!=len){
                            i--;
                        }
                        double num = stod(numStr);    // 将字符串转换为浮点数
                        double temp = Num.top() / num;    // 计算除法结果
                        Num.pop();
                        Num.push(temp);
                    } else if (k == '(') {
                        string op;
                        while (1) {
                            char stTemp = std[i++];
                            if (stTemp == ')') {
                                break;
                            }
                            op += stTemp;
                        }
                        double temp = Load_Stack(op, TempNum, TempSymbol);    // 递归计算括号内的表达式结果
                        temp = Num.top() / temp;    // 计算除法结果
                        stack<double>().swap(TempNum);    // 清空临时操作数栈
                        stack<char>().swap(TempSymbol);    // 清空临时运算符栈
                        Num.pop();
                        Num.push(temp);
                    }
                    break;
                case '%':
                    k = std[i++];
                    if (('0' <= k && k <= '9') || k == '.') {
                        string numStr;
                        if(i==len){
                            numStr+=k;
                        }
                        while ((('0' <= k && k <= '9') || k == '.') && i < len) {
                            numStr += k;
                            k = std[i++];
                            if(i==len)
                                numStr+=k;
                        }
                        if(i!=len){
                            i--;
                        }
                        double num = stod(numStr);    // 将字符串转换为浮点数
                        double temp = fmod(Num.top(), num);    // 计算取模结果
                        Num.pop();
                        Num.push(temp);
                    } else if (k == '(') {
                        string op;
                        while (1) {
                            char stTemp = std[i++];
                            if (stTemp == ')') {
                                break;
                            }
                            op += stTemp;
                        }
                        double temp = Load_Stack(op, TempNum, TempSymbol);    // 递归计算括号内的表达式结果
                        temp = fmod(Num.top(), temp);    // 计算取模结果
                        stack<double>().swap(TempNum);    // 清空临时操作数栈
                        stack<char>().swap(TempSymbol);    // 清空临时运算符栈
                        Num.pop();
                        Num.push(temp);    // 将括号内表达式的结果压入操作数栈
                        break;
                    }
                    break;
                case '(':
                    string op;
                    while (1) {
                        char stTemp = std[i++];
                        if (stTemp == ')') {
                            break;
                        }
                        op+= stTemp;
                    }
                    double temp = Load_Stack(op, TempNum, TempSymbol);    // 递归计算括号内的表达式结果
                    stack<double>().swap(TempNum);    // 清空临时操作数栈
                    stack<char>().swap(TempSymbol);    // 清空临时运算符栈
                    Num.push(temp);    // 将括号内表达式的结果压入操作数栈
                    break;
            }
        }
    }

    double sum = Num.top();    // 最终计算结果
    Num.pop();
    while (!Num.empty() && !Symbol.empty()) {
        switch (Symbol.top()) {
            case '+':
                sum += Num.top();    // 加法运算
                Num.pop();
                break;
            case '-':
                sum = Num.top() - sum;    // 减法运算
                Num.pop();
                break;
        }
        Symbol.pop();
    }
    return sum;
}

int main() {
    fstream filein;
    filein.open("../test1",ios::in);
    if(!filein.is_open()){
        exit(0);
    }
    string temp;
    int i=1;
    while (filein>>temp){
        cout<<"第"<<i<<"个表达式"<<endl;
        i++;
        if(!isExpressionValid(temp)){
            continue;
        }
        if(temp[0]=='#'){
            temp.erase(temp.begin());
        }
        if(temp[temp.length()-1]=='#'){
            temp.erase(temp.end()-1);
        }
        Res.push_back(temp);
        cout << Load_Stack(Res[0], Numk, Symbolk) << endl;    // 计算表达式的结果并输出
        Res.clear();
        stack<double>().swap(TempNum);
        stack<char>().swap(TempSymbol);
        stack<double>().swap(Numk);
        stack<char>().swap(Symbolk);
    }
    filein.close();
}