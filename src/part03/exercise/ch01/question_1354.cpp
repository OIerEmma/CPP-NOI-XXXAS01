//
// Created by Emma on 2025/8/20.
//
#include<iostream>
using namespace std;

char stack[256];

bool check(string s) {
    int i = 0, top = 0;
    while (i < s.size()) {
        if (s[i] == '(' || s[i] == '[') {
            stack[top++] = s[i];
        }
        if (s[i] == ')' || s[i] == ']') {
            if (top <= 0) {
                return false;
            }
            if (s[i] == ')' && stack[top - 1] != '(') {
                return false;
            }
            if (s[i] == ']' && stack[top - 1] != '[') {
                return false;
            }
            top--;
        }
        i++;
    }
    return top == 0;
}

int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        if (check(s)) {
            // cout << "OK" << endl;
            cout << "Yes" << endl;
        } else {
            // cout << "Wrong" << endl;
            cout << "No" << endl;
        }
    }
    return 0;
}
