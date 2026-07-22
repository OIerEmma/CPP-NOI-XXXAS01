//
// Created by Amy on 2026/5/4.
//
#include<iostream>
using namespace std;

int main() {
    double x, z;
    int s;
    cin >> x >> z;
    z /= 10;
    s = x * z;
    s += 5;
    s /= 10;
    s *= 10;
    cout << s;
    return 0;
}
