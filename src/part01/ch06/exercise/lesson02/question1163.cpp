//
// Created by Emma on 2025/3/8.
//
#include<iostream>
using namespace std;

int akm(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return akm(m - 1, 1);
    }
    return akm(m - 1, akm(m, n - 1));
}

int main() {
    int n, m;
    cin >> m >> n;
    printf("%d\n", akm(m, n));
    return 0;
}