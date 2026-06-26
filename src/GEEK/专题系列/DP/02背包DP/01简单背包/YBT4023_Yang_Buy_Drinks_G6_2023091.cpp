//
// Created by Geek.Kwok on 5/6/26.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, L, cost[505], volume[505];

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) cin >> cost[i] >> volume[i];
    // 状态：01背包至少装满问题
    // 初始化
    vector<int> dp(L + 1, INF);
    dp[0] = 0;
    // 计算顺序
    for (int i = 0; i < N; i++)
        for (int j = L; j >= 0; j--)
            if (dp[max(j - volume[i], 0)] != INF) // 确保从可达状态转移过来
                dp[j] = min(dp[j], dp[max(j - volume[i], 0)] + cost[i]);
    // 返回结果
    if (dp[L] == INF) cout << "no solution" << endl;
    else cout << dp[L] << endl;
    return 0;
}