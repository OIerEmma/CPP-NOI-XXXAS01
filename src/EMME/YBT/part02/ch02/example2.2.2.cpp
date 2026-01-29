//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    bool flag;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        flag = true;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}