//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

int main() {
    int a, b;
    char op;
    cin >> a >> b >> op;
    if (op == '/' && b == 0) {
        cout << "Divided by zero!";
    } else if (op != '/' && op != '+' && op != '-' && op != '*') {
        cout << "Invalid operator!";
    } else {
        switch (op) {
            case '+':
                cout << a + b << endl;
            break;
            case '-':
                cout << a - b << endl;
            break;
            case '*':
                cout << a * b << endl;
            break;
            case '/':
                cout << a / b << endl;
            break;
        }
    }
    return 0;
}