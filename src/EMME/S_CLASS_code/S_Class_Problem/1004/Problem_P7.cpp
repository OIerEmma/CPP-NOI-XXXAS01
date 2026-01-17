//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

int to_int(string s) {
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        ans = ans * 10 + (s[i] - 48);
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    int pos = 3, t = 2;
    if (s[2] == ' ') {
        pos = 5;
        t++;
    }
    int a = to_int(s.substr(0, 2));
    int b = to_int(s.substr(pos, 2));
    if (s[t] == '+') {
        cout << a + b << endl;
    } else if (s[t] == '-') {
        cout << a - b << endl;
    } else if (s[t] == '*') {
        cout << a * b << endl;
    } else if (s[t] == '/') {
        cout << a / b << endl;
    } else {
        cout << a % b << endl;
    }
    return 0;
}