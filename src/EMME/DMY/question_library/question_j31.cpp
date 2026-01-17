//
// Created by Emme.Kwok on 2026/1/10.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
        swap(a, b);
    }
    if (a > c) {
        swap(a, c);
    }
    if (b > c) {
        swap(c, b);
    }
    cout << a << " " << b << " " << c;
    return 0;
}