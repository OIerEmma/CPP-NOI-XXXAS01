//
// Created by Amy on 2026/6/13.
//
#include<iostream>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
        if (a < c) {
            cout << c;
        } else {
            cout << a;
        }
    }
    if (a < b) {
        if (b > c) {
            cout << b;
        } else {
            cout << c;
        }
    }
    return 0;
}
