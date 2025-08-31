//
// Created by Emma on 2025/8/28.
//
#include<iostream>
using namespace std;

int a[10001], b[10001];

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        b[i] = i;
    }
    int i = 1, f1 = 1, r1 = m, f2 = 1, r2 = n;
    while (i <= k) {
        printf("%d %d\n", a[f1], b[f2]);
        r1++;
        a[r1] = a[f1];
        f1++;
        r2++;
        b[r2] = b[f2];
        f2++;
        i++;
    }
    return 0;
}