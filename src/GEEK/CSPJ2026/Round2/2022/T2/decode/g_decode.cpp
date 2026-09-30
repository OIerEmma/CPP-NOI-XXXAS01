//
// Created by Geek.Kwok on 2026/9/30.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_decode.in", "r", stdin);
    // freopen("g_decode.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int k;
    long long n, d, e, m, delta, s_delta;
    cin >> k;
    while (k--) {
        // cin >> n >> d >> e;
        scanf("%lld %lld %lld", &n, &d, &e);
        m = n + 2 - e * d;
        delta = m * m - 4 * n;
        s_delta = (long long)sqrt(delta);
        if (s_delta * s_delta == delta && (m + s_delta) % 2 == 0 && (m - s_delta) % 2 == 0) {
            printf("%lld %lld\n", (m - s_delta) / 2, (m + s_delta) / 2);
            // cout << (m - s_delta) / 2 << " " << (m + s_delta) / 2 << "\n";
        }
        else printf("NO\n");
        // else cout << "NO\n";
    }
    return 0;
}