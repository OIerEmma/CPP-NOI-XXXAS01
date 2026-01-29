//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int main() {
    int n, k;
    scanf("%d", &n);
    int temp, a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        k = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        if (k != i) {
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}