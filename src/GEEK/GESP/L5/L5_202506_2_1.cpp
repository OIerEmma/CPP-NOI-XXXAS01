//
// Created by Geek.Kwok on 2026/3/12.
//
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, q, a[100005], g, ans, b[505], f;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i > 1 && a[i] != a[i - 1]) {
            f = 1;
        }
    }

    if (!f) {
        // 全部相等
        for (int i = 1; i <= q; i++) {
            printf("%d\n", a[1] + i);
        }
    } else {
        // 计算原始 g
        g = gcd(a[1], a[2]);
        for (int i = 3; i <= n; i++) {
            g = gcd(g, a[i]);
            if (g == 1) {
                break;
            }
        }
        b[0] = g;
        for (int i = 1; i <= q; i++) {
            // 情况2
            if (g != 1 && i % g == 0) {
                printf("%d\n", g);
                continue;
            }

            // 情况3：记忆化备忘录
            if (g != 1 && b[i % g]) {
                printf("%d\n", b[i % g]);
            } else {
                // 实时计算
                ans = gcd(a[1] + i, a[2] + i);
                for (int j = 3; j <= n; j++) {
                    // 情况1
                    if (ans == 1) {
                        break;
                    }
                    ans = gcd(ans, a[j] + i);
                }
                printf("%d\n", b[i]=ans);
            }
        }
    }
    return 0;
}