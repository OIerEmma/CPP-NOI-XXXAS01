//
// Created by Emma on 2025/1/1.
//
#include<iostream>
#define INF 1000000000
using namespace std;

int main() {
    int x, n = 0, min = INF, max = -INF, s = 0;
    while (scanf("%d", &x) == 1) {
        s += x;
        min = x < min ? x : min;
        max = x > max ? x : max;
        ++n;
    }
    printf("%d %d %.3lf\n", min, max, s * 1.0 / n);
    return 0;
}