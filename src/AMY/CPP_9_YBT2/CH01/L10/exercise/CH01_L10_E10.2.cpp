//
// Created by Amy on 2026/5/4.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double a;
    cin >> a;
    if (a > 0) {
        cout << int(a);
    }else {
        std::ceil(a);
    }
    return 0;
}