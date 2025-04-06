//
// Created by Emma on 2025/3/28.
//
#include<iostream>
#include<cstring>
using namespace std;

int a[1000000];

int pell(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (a[n] > 0) {
        return a[n];
    }
    a[n] = 2 * pell(n - 1) % 32767 + pell(n - 2) % 32767;
    return a[n] % 32767;
}

int main() {
    int k, t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> k;
        memset(a, 0, sizeof(a));
        printf("%d\n", pell(k));
    }
    return 0;
}
