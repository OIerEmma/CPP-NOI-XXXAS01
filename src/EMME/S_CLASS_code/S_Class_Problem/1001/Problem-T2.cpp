//
// Created by Emma on 2025/2/4.
//
#include<iostream>

using namespace std;

int main() {
    double x, ans;
    cin >> x;
    if (x < 5.0 && x >= 0.0) {
        ans = -x + 2.5;
    } else if (x < 10.0 && x >= 5.0) {
        ans = 2 - 1.5 * (x - 3) * (x - 3);
    } else {
        ans = x / 2 - 1.5;
    }
    printf("%.3lf", ans);
    return 0;
}
