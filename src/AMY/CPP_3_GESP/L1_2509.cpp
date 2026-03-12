//
// Created by Amy on 2026/3/8.
//
#include<iostream>
using namespace std;

int main() {
    int x, y, n, p;
    double sum=0;
    double num=0;
    cin >> x >> y >> n >> p;
    if (p > x) {
        sum = p - y;
    }
    num = (n * 0.1) * p;
    if (num > sum) {
        printf("%.2lf", sum);
    }
    if (sum > num) {
        printf("%.2lf", num);
    }
    return 0;
}
