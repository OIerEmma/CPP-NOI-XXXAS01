//
// Created by Emma on 2025/5/30.
//
#include<iostream>
using namespace std;

int f[10010][2];

int main() {
    int n, x;
    scanf("%d", &n);
    f[1][1] = 1;
    f[1][0] = 9;
    for (int i = 2; i <= n; i++) {
        x = f[1][0];
        if (i == n) {
            x--;
        }
        f[i][0] = (f[i - 1][0] * x + f[i - 1][1]) % 12345;
        f[i][1] = (f[i - 1][1] * x + f[i - 1][0]) % 12345;
    }
    printf("%d", f[n][0]);
    return 0;
}