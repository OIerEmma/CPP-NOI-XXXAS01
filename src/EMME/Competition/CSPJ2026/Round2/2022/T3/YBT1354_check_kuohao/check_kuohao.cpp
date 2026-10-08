//
// Created by Geek.Kwok on 2026/10/3.
//
#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> op;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (op.empty() || op.top() != '(') return false;
            op.pop();
        } else if (s[i] == ']') {
            if (op.empty() || op.top() != '[') return false;
            op.pop();
        } else op.push(s[i]);
    }
    if (!op.empty()) return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (check(s) ? "OK" : "Wrong") << endl;
    return 0;
}