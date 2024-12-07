//
// Created by Emma on 2024/12/7.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    double y, x;
    cin >> x;
    if(x < 5 && x <= 0) {
        y = -x + 2.5;
    } else if(x <= 5 && x < 10) {
        y = 2 - 1.5 * (x - 3) * (x - 3);
    } else {
        y = x / 2 - 1.5;
    }
    printf("%.3lf", y);
    return 0;
}