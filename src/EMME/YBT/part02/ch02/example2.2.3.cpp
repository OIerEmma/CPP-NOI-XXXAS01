//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

int main() {
    int n, j, temp, k;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (a[i] >= a[j]) {
                break;
            }
        }
        if (j != i - 1) {
            temp = a[i];
            for (k = i - 1; k > j; k--) {
                a[k + 1] = a[k];
            }
            a[k + 1] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}