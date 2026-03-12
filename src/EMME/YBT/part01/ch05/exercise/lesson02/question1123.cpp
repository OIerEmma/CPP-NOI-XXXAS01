//
// Created by Emma on 2025/1/22.
//
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int m, n;

int main() {
    cin >> m >> n;
    int a[m + 1][n + 1], b[m + 1][n + 1];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    double sum = 0.00;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == b[i][j]) sum++;
        }
    }
    double const temp = sum / (m * n) * 100.0;
    printf("%.2lf", temp);
    return 0;
}
