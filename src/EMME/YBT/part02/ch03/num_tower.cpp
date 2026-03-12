//
// Created by Emma on 2025/4/21.
//
#include<iostream>
using namespace std;

int a[100][100];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (a[i + 1][j] >= a[i + 1][j + 1]) {
                a[i][j] += a[i + 1][j];
            } else {
                a[i][j] += a[i + 1][j + 1];
            }
        }
    }
    printf("%d", a[0][0]);
    return 0;
}