//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    bool odd_flag = false;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            if (!odd_flag) {
                printf("%d", a[i]);
                odd_flag = true;
            } else {
                printf(",%d", a[i]);
            }
        }
    }
    return 0;
}