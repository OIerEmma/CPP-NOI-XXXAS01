//
// Created by Amy on 2026/5/4.
//
#include<iostream>
using namespace std;

int main() {
    int a,b,c,x;
    cin >> x;
    a = b = c = x / 3;
    a /= 2;
    b /= 2;
    c = c + b + a;
    a /= 2;
    c /= 2;
    b = b + a + c;
    b /= 2;
    c /= 2;
    a = a + b + c;
    cout << a << " " << b << " " << c << endl;
    return 0;
}
