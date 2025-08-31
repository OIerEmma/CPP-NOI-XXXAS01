//
// Created by Emma on 2025/8/22.
//
#include <iostream>
#include <cmath>
using namespace std;

const int MAXLEN = 10001;
char stk[MAXLEN];
int istk[MAXLEN];
int top = -1, itop = -1;

// 判断中缀表达式是否合法
bool judge(string midStr) {
    int n = 0;
    string t = "", ops = "+*/^", ops2 = "+-*/^";
    // 检查第一个字符是否为运算符
    if (ops.find(midStr[0]) != string::npos) {
        return false;
    }
    // 检查最后一个字符是否为运算符
    if (ops2.find(midStr[midStr.length() - 1]) != string::npos) {
        return false;
    }
    // 检查括号是否匹配
    for (int i = 0; i < midStr.length(); i++) {
        if (midStr[i] == '(') {
            n++;
        } else if (midStr[i] == ')') {
            n--;
        } else {
            t += midStr[i];
        }
    }
    if (n) { return false; }
    // 检查运算符是否合法
    for (int i = 1; i < t.length(); i++) {
        if (ops.find(t[i]) != string::npos && ops2.find(t[i - 1]) != string::npos) {
          return false;
        }
    }
    return true;
}

int order(char ch) {
    // 运算符优先级：括号<加减<乘除<幂
    if (ch == '(') return 0;
    else if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 3;
    else return 4;
}

// 中缀表达式转后缀表达式
string getPostStr(string midStr) {
    bool first = true;
    string postStr = "";
    for (int i = 0; i < midStr.length(); i++) {
        // 1.遇到操作数，直接输出；
        if (midStr[i] >= '0' && midStr[i] <= '9') {
            // 第一个操作数前不加空格
            if (first) { first = false; }
            else { postStr += ' '; }
            // 操作数可能不止一位，所以需要循环
            postStr += midStr[i++];
            while (i < midStr.length() && midStr[i] >= '0' && midStr[i] <= '9') {
                postStr += midStr[i++];
            }
            i--;
        }
        // 3.遇到左括号，将其入栈；
        else if (midStr[i] == '(') {
            stk[++top] = midStr[i];
        }
        // 4.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出；
        else if (midStr[i] == ')') {
            while (top >= 0 && stk[top] != '(') {
                postStr += ' ';
                postStr += stk[top--];
            }
            // 与之匹配的左括号弹出
            top--;
        }
        // 5.遇到其他运算符’+”-”*”/”^’时，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈；
        else {
            while (top >= 0 && stk[top] != '(' && order(stk[top]) >= order(midStr[i])) {
                postStr += ' ';
                postStr += stk[top--];
            }
            // 2.栈为空时，遇到运算符，入栈；
            stk[++top] = midStr[i];
        }
    }
    // 6.遍历结束，将栈中剩余的元素依次弹出，并输出；
    while (top >= 0) {
        postStr += ' ';
        postStr += stk[top--];
    }
    return postStr;
}

// 后缀表达式求值
int getPostVal(string postStr) {
    int val = 0;
    for (int i = 0; i < postStr.length(); i++) {
        if (postStr[i] == ' ') {
            continue;
        }
        // 1. 为操作数时，数字字符时转换为数字并入栈
        if (postStr[i] >= '0' && postStr[i] <= '9') {
            // 操作数可能不止一位，所以需要循环
            val = 0;
            do {
                val = val * 10 + (postStr[i] - '0');
                i++;
            } while (i < postStr.length() && postStr[i] >= '0' && postStr[i] <= '9');
            i--;
            istk[++itop] = val;
        }
        // 2. 为运算符时，弹出两个操作数，计算结果并入栈
        else {
            switch (postStr[i]) {
                case '+':
                    istk[itop - 1] = istk[itop - 1] + istk[itop];
                    break;
                case '-':
                    istk[itop - 1] = istk[itop - 1] - istk[itop];
                    break;
                case '*':
                    istk[itop - 1] = istk[itop - 1] * istk[itop];
                    break;
                case '/':
                    istk[itop - 1] = istk[itop - 1] / istk[itop];
                    break;
                case '^':
                    istk[itop - 1] = pow(istk[itop - 1], istk[itop]);
                    break;
            }
            itop--;
        }
    }
    return istk[itop];
}

int main() {
    string midStr, postStr = "";
    cin >> midStr;
    midStr = midStr.substr(0, midStr.find('@'));
    // cout << midStr << endl;
    if (judge(midStr)) {
        postStr = getPostStr(midStr);
        // cout << postStr << endl;
        cout << getPostVal(postStr) << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}