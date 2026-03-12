//
// Created by Emma on 2025/8/19.
//
#include<iostream>
using namespace std;

char c[256];

bool judge(const char c[256]) {
    int top = 0, i = 0;
    while (c[i] != '@') {
        if (c[i] == '(') {
            top++;
        }
        if (c[i] == ')') {
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
    cin >> c;
    if (judge(c)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}