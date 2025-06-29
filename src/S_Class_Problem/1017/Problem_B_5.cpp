//
// Created by Emma on 2025/4/23.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            ans += i;
        }
    }
    printf("%d", ans);
    return 0;
}