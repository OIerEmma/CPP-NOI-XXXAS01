//
// Created by Emme.Kwok on 2026/6/25.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 读入数据
    int n, k;
    cin >> n >> k;
    vector<int> a(n), c(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) cin >> a[i] >> c[i], cnt += a[i];
    // 核心算法
    // 状态：dp[i]代表总攻击力达到i时的最少金币花费
    vector<int> dp(cnt + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = cnt; j >= a[i - 1]; j--)
            dp[j] = min(dp[j], dp[j - a[i - 1]] + c[i - 1]);
    // 输出结果
    int ans = -1;
    for (int i = cnt; i >= 0; i--) if (dp[i] <= k) {ans = i; break;}
    cout << ans << endl;
    return 0;
}