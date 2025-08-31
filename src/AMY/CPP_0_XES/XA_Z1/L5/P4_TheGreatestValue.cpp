//
// Created by Emma on 2025/8/31.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ans = max(ans, x);
    }
    printf("%d", ans);
    return 0;
}
