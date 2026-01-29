//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

int main() {
    int n, k, ans = 0, b[1001];
    scanf("%d", &n);
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (b[k] < 1) {
            ans++;
        }
        b[k]++;
    }
    printf("%d\n", ans);
    for (int i = 0; i <= 1000; i++) {
        if (b[i] >= 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
