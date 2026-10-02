//
// Created by Geek.Kwok on 2026/10/2.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_exchange_bus.in", "r", stdin);
    // freopen("g_exchange_bus.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    const int MAXN = 100005;
    int n, ans = 0, t[MAXN][4]; // t[][0] 工具 t[][1] 价格 t[][2] 时间 t[][3] 优惠是否已使用
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i][0] >> t[i][1] >> t[i][2];
        t[i][3] = 0;
        if (t[i][0] == 0) ans += t[i][1];
        else {
            bool free = false;
            int prev = -1;
            for (int j = i - 1; j >= 0; j--) {
                // 从后往前找满足条件的记录
                // 1. t[j][0] == 0 && t[j][3] == 0
                // 2. 时间小于45mins：t[i][2] - t[j][2] <= 45
                // 3. 价格小于：t[i][1] <= t[j][1]
                if (t[j][0] == 1 || t[j][3] == 1) continue;
                if (t[i][2] - t[j][2] > 45) break;
                if (t[i][1] > t[j][1]) continue;
                prev = j; free = true;
            }
            if (!free) {
                ans += t[i][1];
            } else if (prev != -1) {
                t[prev][3] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}