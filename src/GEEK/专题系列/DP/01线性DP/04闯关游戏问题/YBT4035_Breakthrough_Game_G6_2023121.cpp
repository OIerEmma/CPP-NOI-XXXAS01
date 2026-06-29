//
// Created by Geek.Kwok on 5/13/26.
//
#include <bits/stdc++.h>
using namespace std;

const int NEG_INF = -1e9;

int main() {
    // input
    int n, m;
    cin >> n >> m;
    vector<int> score(n), channel(m);
    for (int i = 0; i < m; i++) cin >> channel[i];
    for (int i = 0; i < n; i++) cin >> score[i];
    // DP[i] 到达第 i 关（不含当前关奖励）可获取的最高分数(0-based)
    // 初始化
    vector<int> dp(n + 1, NEG_INF); // 初始化为极小负数，表示暂不可达
    dp[0] = 0; // 站在第 0 关，得分 0
    // 计算顺序 正序递推：计算到达每一关的最大得分
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i - channel[j] >= 0)
                dp[i] = max(dp[i], dp[i - channel[j]] + score[i - channel[j]]);
    // 返回结果 枚举所有能“一步通关”的起跳点
    int ans = NEG_INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + channel[j] >= n) {
                ans = max(ans, dp[i] + score[i]);
                break; // 只要有一个通道能通关，结果都一样
            }
    cout << ans << endl;
}