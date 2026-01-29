//
// Created by Emma on 2025/4/4.
//
#include <iostream>
#include <valarray>
using namespace std;

int apple_number(int m, int n) {
    if (m < 0 || n < 0) {
        return 0;
    }
    if (m <= 1 || n <= 1) {
        return 1;
    }
    return apple_number(m, n - 1) + apple_number(m - n, n);
}

int main() {
    int m, n, t;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d", &m, &n);
        printf("%d\n", apple_number(m, n));
    }
    return 0;
}
