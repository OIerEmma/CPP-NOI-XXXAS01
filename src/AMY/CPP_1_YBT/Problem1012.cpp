//
// Created by Amy on 2025/12/20.
//
#include<iostream>
using namespace std;
int main() {
    double a, b, c, d, x, f;
    cin >> x >> a >> b >> c >> d;
    f = a*x*x*x + b*x*x + c*x + d;
    printf("%0.7f",f);
    return 0;
}