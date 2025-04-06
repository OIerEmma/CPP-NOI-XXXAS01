//
// Created by Emma on 2025/4/5.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}