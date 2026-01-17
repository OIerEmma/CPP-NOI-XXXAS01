//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;

int main() {
    int num1, num2;
    char op;
    cin >> num1 >> num2 >> op;
    switch(op) {
        case '+':
            cout << num1 + num2 << endl;
        break;
        case '-':
            cout << num1 - num2 << endl;
        break;
        case '*':
            cout << num1 * num2 << endl;
        break;
        case '/':
            if(num2 != 0) {
                cout << num1 / num2 << endl;
                break;
            } else {
                cout << "Divided by zero!" << endl;
                break;
            }
        default:
            cout << "Invalid operator!" << endl;
        return 0;
    }
}