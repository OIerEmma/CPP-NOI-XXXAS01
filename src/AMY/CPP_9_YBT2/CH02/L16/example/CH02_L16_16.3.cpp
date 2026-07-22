//
// Created by Amy on 2026/6/13.
//
#include<iostream>
using namespace std;

int main() {
    double w;
    cin >> w;
    if (w <= 20) printf("%.2lf", w * 1.68);
    if (w > 20) printf("%.2lf", w * 1.98);
    return 0;
}