//
// Created by Geek.Kwok on 6/24/26.
//
#include <bits/stdc++.h>
using namespace std;

// --- 01背包模板 ---

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(105), v(105);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    // 状态：dp[j] = 容量为j时的最大价值
    vector<int> dp(10005, 0); // 全部初始化为0
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--) // 倒序遍历
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    // 答案
    cout << dp[W] << endl;
    return 0;
}

// --- 变体1：恰好背包模板 ---

const int INF = 1e9;

int main2() {
    int n, W;
    cin >> n >> W;
    vector<int> w(105), v(105);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    // 状态：dp[j] = 容量恰好为j时的最小花费
    vector<int> dp(10005, INF);  // 差异1：全部初始化为INF
    dp[0] = 0;                          // 差异1：容量0时花费0
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--) // 倒序遍历
            if (dp[j - w[i]] != INF) // 差异2：来源状态可达
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
    // 答案
    if (dp[W] == INF) cout << "no solution" << endl; // 差异3：无法恰好装满
    else cout << dp[W] << endl;
    return 0;
}

// --- 变体2：至少背包模板 ---

int main3() {
    int n, W;
    cin >> n >> W;
    vector<int> w(105), v(105);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    // 状态：dp[j] = 容量恰好为j时的最小花费
    vector<int> dp(10005, INF);  // 全部初始化为INF
    dp[0] = 0;                          // 容量0时花费0
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = W; j >= 0; j--) // 差异1：倒序遍历直到0
            if (dp[max(j - w[i], 0)] != INF) // 来源状态可达
                dp[j] = min(dp[j], dp[max(j - w[i], 0)] + v[i]); // 差异2：容量超出时当恰好装满处理(从dp[0]转移来)
    // 答案
    if (dp[W] == INF) cout << "no solution" << endl; // 无法至少装满
    else cout << dp[W] << endl;
    return 0;
}

// --- 计数背包模板(与01背包模板差异) ---

const int MOD = 1e9 + 7;

int main4() {
    int n, W;
    cin >> n >> W;
    vector<int> w(105), v(105);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    // 状态：dp[j] = 容量为j时的方案数
    vector<int> dp(10005, 0); // 全部初始化为0
    dp[0] = 1; // 差异1：容量0时有1种方案数即什么都不选
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = W; j >= w[i]; j--) // 倒序遍历
            dp[j] = (dp[j] + dp[j - w[i]]) % MOD; // 差异2：方案数相加取模
    // 答案
    cout << dp[W] << endl;
    return 0;
}

// --- 一维DP模板 ---

int main5() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 状态：dp[i] = 达到第i个位置时的最优值
    vector<int> dp(n, 0); // 全部初始化为0
    dp[0] = a[0], dp[1] = a[0] + a[1]; // 或者 max(a[0], a[1]) 具体看题意
    // 顺序
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]); // 选或不选
    // 答案
    cout << dp[n - 1] << endl;
    return 0;
}
