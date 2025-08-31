//
// Created by Emma on 2025/8/21.
//
#include <iostream>
using namespace std;

const int MAXLEN = 10001;
char stk[MAXLEN];
long long stkn[MAXLEN];
int top = -1;

int order(char ch) {
    // 运算符优先级：括号<加减<乘除<幂
    if (ch == '(') return 0;
    else if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 3;
    else return 4;
}

string getPostStr(string midStr) {
    bool first = true;
    string postStr;
    for (int i = 0; i < midStr.length(); i++) {
        // 1.遇到操作数，直接输出；
        if (midStr[i] >= '0' && midStr[i] <= '9') {
            if (first) { first = false; } else { postStr += ' '; }
            postStr += midStr[i++];
            while (i < midStr.length() && midStr[i] >= '0' && midStr[i] <= '9') {
                postStr += midStr[i++];
            }
            i--;
        }
        // 2.遇到左括号，将其入栈；
        else if (midStr[i] == '(') {
            stk[++top] = midStr[i];
        }
        // 3.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出；
        else if (midStr[i] == ')') {
            while (top >= 0 && stk[top] != '(') {
                postStr += ' ';
                postStr += stk[top--];
            }
            // 与之匹配的左括号弹出
            top--;
        }
        // 4.遇到其他运算符’+”-”*”/”^’时，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈；
        else {
            while (top >= 0 && stk[top] != '(' && order(stk[top]) >= order(midStr[i])) {
                postStr += ' ';
                postStr += stk[top--];
            }
            // 2.栈为空时，遇到运算符，入栈；
            stk[++top] = midStr[i];
        }
    }
    // 5.遍历结束，将栈中剩余的元素依次弹出，并输出；
    while (top >= 0) {
        postStr += ' ';
        postStr += stk[top--];
    }
    return postStr;
}

long long comp(string s) {
    int i = 0, top = 0;
    memset(stackk, 0, sizeof(stackk));
    if (s.size() <= 1) {
        return 0;
    }
    // s.size() - 1
    // 16 9 4 3 +*-@@ dfs @#ddk
    while (s[i] != '@') {
        switch (s[i]) {
            case '+':
                top--;
            stackk[top] += stackk[top + 1];
            break;
            case '-':
                top--;
            stackk[top] -= stackk[top + 1];
            break;
            case '*':
                top--;
            stackk[top] *= stackk[top + 1];
            break;
            case '/':
                top--;
            stackk[top] /= stackk[top + 1];
            break;
            default:
                long long x = 0;
            while (s[i] != ' ') {
                x = x * 10 + (s[i++] - '0');
            }
            stackk[++top] = x;
            break;
        }
        i++;
        // cout << stackk[top] << endl;
    }
    return stackk[top];
}

int main() {
    string midStr, postStr = "";
    cin >> midStr;
    postStr = getPostStr(midStr);
    cout << postStr << endl;
    return 0;
}
