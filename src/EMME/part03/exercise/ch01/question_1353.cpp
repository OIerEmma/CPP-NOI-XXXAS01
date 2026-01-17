//
// Created by Emma on 2025/8/20.
//
#include<iostream>
using namespace std;

bool checkkuohao(string s) {
    int top = 0, i = 0;
    while (s[i] != '@') {
        if (s[i] == '(') {
            top++;
        }
        if (s[i] == ')') {
            if (top > 0) {
                top--;
            } else {
                return false;
            }
        }
        i++;
    }
    if (top != 0) {
        return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if (checkkuohao(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}