//
// Created by Emma on 2025/7/2.
//
#include<iostream>
using namespace std;

int a[15][15];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", a, i + 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", i + 1, b);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 - a == j + 1 - b) {
                printf("(%d,%d) ", i + 1, j + 1);
            }
        }
    }
    printf("\n");
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i + 1 - a == -(j + 1 - b)) printf("(%d,%d) ", i + 1, j + 1);
        }
    }
    printf("\n");
    return 0;
}