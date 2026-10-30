//
// Created by Geek.Kwok on 2026/10/30.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
int m, k, n, C;
struct Mat {
    int s, q, h;
} a[N];

bool cmp(const Mat& a, const Mat& b) { return a.s < b.s; }

int main() {
    // freopen("baker.in", "r", stdin); freopen("baker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // ...解题...
    cin >> m >> k >> n >> C;
    for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].q >> a[i].h;
    sort(a + 1, a + n + 1, cmp);
    // 最值型01背包变形:
    // dp[m*k][C]: 前 k 个月资金消耗不超过m*k且半价次数已使用C次的获得的成就感最大值
    const int NEG = -1e9;
    vector<vector<int>> dp(m * k + 1, vector<int>(2, NEG));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        // 本原料不使用VIP特权
        for (int j = a[i].s * m; j >= 0; j--) {
            if (j >= a[i].q) {
                // 之前没用特权现在也没用特权
                dp[j][0] = max(dp[j][0], dp[j - a[i].q][0] + a[i].h);
                // 之前已使用特权现在不能用了
                dp[j][1] = max(dp[j][1], dp[j - a[i].q][1] + a[i].h);
            }
            // 本原料使用VIP特权
            if (C && j >= (a[i].q + 1) / 2)
                dp[j][1] = max(dp[j][1], dp[j - (a[i].q + 1) / 2][0] + a[i].h); // 之前没用特权现在使用特权
        }
    }
    int ans = 0;
    for (int i = 0; i <= m * k; i++) ans = max(ans, max(dp[i][0], dp[i][1]));
    cout << ans << endl;
    return 0;
}