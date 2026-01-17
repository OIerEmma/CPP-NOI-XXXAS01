//
// Created by Emma on 2025/8/23.
//
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

// 数字栈和符号栈
char s_op[1001];
long long s_nm[1001];
int top_nm = 0, top_op = 0;

bool order(const char ch1, const char ch2) {
    // ch1最高优先级
    if (ch1 == '^') {
        return true;
    }
    // ch2最高优先级
    if (ch2 == '^') {
        return false;
    }
    // ch2最低优先级
    if (ch2 == ')') {
        return true;
    }
    // ch1较高优先级
    if (ch1 == '*' || ch1 == '/') {
        return true;
    }
    // ch1较低优先级
    if (ch1 == '+' || ch1 == '-') {
        if (ch2 == '+' || ch2 == '-') {
            return true;
        }
    }
    return false;
}

// 一次栈顶运算，计算结果入栈
void calculate(char op) {
    if (top_op - 1 >= 0) {
        switch (op) {
            case '+':
                s_nm[top_nm - 2] = s_nm[top_nm - 2] + s_nm[top_nm - 1];
                break;
            case '-':
                s_nm[top_nm - 2] = s_nm[top_nm - 2] - s_nm[top_nm - 1];
                break;
            case '*':
                s_nm[top_nm - 2] = s_nm[top_nm - 2] * s_nm[top_nm - 1];
                break;
            case '/':
                s_nm[top_nm - 2] = s_nm[top_nm - 2] / s_nm[top_nm - 1];
                break;
            case '^':
                s_nm[top_nm - 2] = pow(s_nm[top_nm - 2], s_nm[top_nm - 1]);
                break;
            default:
                cout << "error operator: " << op << endl;
                break;
        }
        top_nm--;
        top_op--;
    } else {
        cout << "none operator" << endl;
    }
}

int main() {
    string s;
    cin >> s;
    getchar();
    memset(s_op, 0, sizeof(s_op));
    memset(s_nm, 0, sizeof(s_nm));
    top_nm = 0, top_op = 0;
    long long tmp = 0;
    for (int i = 0; s[i] != '@'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            // 如果当前字符是数字，则入数字栈
            // cout << "nm: " << s[i] << endl;
            tmp = tmp * 10 + (s[i] - '0');
        } else {
            // 如果当前字符是符号，则入符号栈
            //cout << "op: " << s[i] << endl;
            if (s[i] == '(') {
                // 左括号入栈
                s_op[top_op++] = s[i];
                continue;
            }
            // 数字先入栈
            s_nm[top_nm++] = tmp;
            if (s[i] == ')') {
                // 遇到右括号，计算括号内的表达式
                while (top_op - 1 >= 0 && s_op[top_op - 1] != '(' && order(s_op[top_op - 1], s[i])) {
                    calculate(s_op[top_op - 1]);
                }
                // 弹出左括号并丢弃右括号
                if (s_op[top_op - 1] == '(') {
                    top_op--;
                    tmp = s_nm[--top_nm];
                }
            } else {
                // 遇到异或乘除加减等符号，先计算更高优先级的运算符，再入栈
                while (top_op - 1 >= 0 && order(s_op[top_op - 1], s[i])) {
                    calculate(s_op[top_op - 1]);
                }
                // 符号入栈
                s_op[top_op++] = s[i];
                tmp = 0;
            }
        }
    }
    if (tmp != 0) {
        s_nm[top_nm++] = tmp;
    }
    // 计算剩余的表达式
    while (top_op - 1 >= 0) {
        calculate(s_op[top_op - 1]);
    }
    cout << s_nm[0] << endl;
    return 0;
}
