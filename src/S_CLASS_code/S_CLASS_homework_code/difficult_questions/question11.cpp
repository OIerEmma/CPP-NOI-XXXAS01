//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int n, d, t;
    int sum = 0, last_t = 0;
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &t);
        if (last_t == 0) {
            last_t = t;
        }
        if (last_t + d >= t) {
            sum += (t - last_t);
        } else {
            sum += d;
        }
        last_t = t;
    }
    sum += d;
    printf("%d", sum);
    return 0;
}