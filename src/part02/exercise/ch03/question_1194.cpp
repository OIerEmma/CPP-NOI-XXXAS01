//
// Created by Emma on 2025/5/31.
//
#include<iostream>
using namespace std;

int a[30][30];

int main() {
    for (int i = 1; i <= 20; i++) { // 行数
        for (int j = 1; j <= 20; j++) { // 列数
            if (i == 0 || j == 1) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i][j - 1] + a[i - 1][j];
            }
        }
    }
    int n, m;
    scanf("%d %d", &m, &n);
    printf("%d\n", a[n][m]);
    return 0;
}