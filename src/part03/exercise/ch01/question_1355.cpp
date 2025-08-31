//
// Created by Emma on 2025/8/20.
//
#include<iostream>
#include<cstring>
using namespace std;

char stackk[256];

bool check(string s) {
    int top = 0, i = 0;
    memset(stackk, 0, sizeof(stackk));
    while (i < s.size()) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(' || s[i] == '<') {
            if ((stackk[top - 1] == '<' && (s[i] == '(' || s[i] == '[' || s[i] == '{'))
                || (stackk[top - 1] == '(' && (s[i] == '[' || s[i] == '{'))
                || (stackk[top - 1] == '[' && s[i] == '{')) {
                return false;
            }
            stackk[top++] = s[i];
        } else if (s[i] == '}') {
            if (stackk[top - 1] != '{' || top <= 0) {
                return false;
            }
            stackk[top - 1] = 0;
            top--;
        } else if (s[i] == ']') {
            if (stackk[top - 1] != '[' || top <= 0) {
                return false;
            }
            stackk[top - 1] = 0;
            top--;
        } else if (s[i] == ')') {
            if (stackk[top - 1] != '(' || top <= 0) {
                return false;
            }
            stackk[top - 1] = 0;
            top--;
        } else if (s[i] == '>') {
            if (stackk[top - 1] != '<' || top <= 0) {
                return false;
            }
            stackk[top - 1] = 0;
            top--;
        }
        i++;
    }
    return top == 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;
        getchar();
        if (check(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
