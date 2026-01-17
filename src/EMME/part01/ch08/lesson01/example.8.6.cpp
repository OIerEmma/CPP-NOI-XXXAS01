//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    int *a;
    scanf("%d", &n);
    a = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    delete []a;
    return 0;
}