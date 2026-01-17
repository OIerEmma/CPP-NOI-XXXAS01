//
// Created by Emma on 2025/2/7.
//
#include<iostream>
using namespace std;

int main() {
    int n, num, ans = -100000000;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        ans = max(ans, num);
    }
    printf("%d", ans);
    return 0;
}