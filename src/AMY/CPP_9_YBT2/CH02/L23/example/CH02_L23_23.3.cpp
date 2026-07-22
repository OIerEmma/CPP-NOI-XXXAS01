//
// Created by Amy on 2026/6/23.
//
#include<bits/stdc++.h>
using namespace std;
int x, y;
char op;
int main() {
    cin >> x >> y >> op;
    switch(op) {
        case '+' : cout << x + y; break;
        case '-' : cout << x - y; break;
        case '*' : cout << x * y; break;
        case '/' : if (y == 0) cout << "Divided by zero!";
        else cout << x / y; break;
        default : cout << "Invalid operator!";
    }
    return 0;
}