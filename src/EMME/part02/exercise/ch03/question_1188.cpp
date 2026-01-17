//
// Created by Emma on 2025/5/30.
//
#include<iostream>
using namespace std;

long long f[1000010];

int main() {
    int n, a;
    scanf("%d", &n);
    f[0] = 1;
    f[1] = 1;
    for (int j = 2; j < 1000000; j++) {
        f[j] = f[j - 1] + f[j - 2];
        f[j] %= 1000;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        printf("%lld\n", f[a - 1]);
    }
    return 0;
}