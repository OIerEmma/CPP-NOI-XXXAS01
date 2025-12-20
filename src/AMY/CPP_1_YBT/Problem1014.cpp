//
// Created by Amy on 2025/12/20.
//
#include<iostream>
using namespace std;
int main() {
    double r, d, p, s;
    cin >> r;
    d = 2*r;
    p = 2*3.14159*r;
    s = 3.14159*r*r;
    printf("%0.4f %0.4f %0.4f",d, p, s);
    return 0;
}