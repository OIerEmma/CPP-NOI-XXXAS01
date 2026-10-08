//
// Created by Geek.Kwok on 2026/10/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    char c;
    cin >> a;
    int m = 10000;
    a = a % m;
    stack<int> x;
    x.push(a);
    while (cin >> c >> b) {
        if (c == '*') {
            a = x.top();
            x.pop();
            x.push(a * b % m);
        } else x.push(b);
    }
    a = 0;
    while ((int)x.size() > 0) {
        a += x.top();
        a %= m;
        x.pop();
    }
    cout << a << endl;
    return 0;
}