//
// Created by Emme.Kwok on 2025/9/21.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    double ans;
    cin >> n;
    if (n >= 10000) {
        ans = n * 0.05;
    } else if (n >= 5000) {
        ans = n * 0.03;
    } else if (n >= 1000) {
        ans = n * 0.02;
    } else {
        ans = 0.0;
    }
    printf("%.2lf\n", ans);
    return 0;
}