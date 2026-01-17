//
// Created by Emma on 2025/5/31.
//
#include<iostream>
using namespace std;

int a[30][30];

int main() {
    int t;
    scanf("%d", &t);
    int m, n;
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (i == 0 || j == 1) {
                a[i][j] = 1;
            } else if (i >= j) {
                a[i][j] = a[i][j - 1] + a[i - j][j];
            } else {
                a[i][j] = a[i][i];
            }
        }
    }
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &m, &n);
        printf("%d\n", a[m][n]);
    }
    return 0;
}