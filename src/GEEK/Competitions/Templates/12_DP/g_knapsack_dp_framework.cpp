//
// Created by Geek.Kwok on 2026/10/30.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int BN = 105, BV = 100005;
int nItem, V, w[BN], v[BN], cntLimit[BN];
ll dp[BV];

// 01背包：每件最多选一次，容量为V，求最大值
ll knapsack01() {
    // dp[j] 容量不超过j时的最大价值
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= nItem; i++)
        for (int j = V; j >= w[i]; j--) // 倒序：保证每件只用一次
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[V];
}

// 完全背包：每件可以选无限次
ll knapsackComplete() {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= nItem; i++)
        for (int j = w[i]; j <= V; j++) // 正序：同一件可以重复用
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[V];
}

// 能否恰好装满容量V（N01T4装箱问题：求剩余空间最小=V-能装到的最大体积）
bool ok[BV];
bool canFill() {
    memset(ok, 0, sizeof(ok));
    ok[0] = true;
    for (int i = 1; i <= nItem; i++)
        for (int j = V; j >= w[i]; j--)
            if (ok[j - w[i]]) ok[j] = true;
    return ok[V];
}

// 方案数：恰好装满V的方案数 mod MODK
const ll MODK = 1000000007;
ll ways[BV];
ll countWays01() {
    memset(ways, 0, sizeof ways);
    ways[0] = 1;
    for (int i = 1; i <= nItem; i ++)
        for (int j = V; j >= w[i]; j--)
            ways[j] = (ways[j] + ways[j - w[i]]) % MODK;
    return ways[V];
}

// 多重背包转01背包（第i件最多cntLimit[i]个）：二进制拆分成若干件01物品
ll knapsackMulti() {
    vector<int> ww, vv;
    for (int i = 1; i <= nItem; i++) {
        int c = cntLimit[i];
        for (int k = 1; c > 0; k *= 2) { // 拆成 1，2，4，...，剩余
            int take = min(c, k);
            ww.push_back(take * w[i]);
            vv.push_back(take * v[i]);
            c -= take;
        }
    }
    memset(dp, 0, sizeof dp);
    for (size_t i = 0; i < ww.size(); i++)
        for (int j = V; j >= ww[i]; j--)
            dp[j] = max(dp[j], dp[j - ww[i]] + vv[i]);
    return dp[V];
}

// 多重背包计数：N12T3摆花，n种花，第i种最多a[i]盆，共摆m盆、按种类顺序，方案数 mod 1000007
// 正序写法
int flowers(int n, int m, const int a[]) {
    const int MODF = 1000007;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> ndp(m + 1, 0);
        for (int j = 0; j <= m; j++)
            for (int t = 0; t <= a[i] && t <= j; t++) // 第i种花摆t盆
                ndp[j] = (ndp[j] + dp[j - t]) % MODF;
        dp = ndp;
    }
    return dp[m];
}
// 多重背包计数：N12T3摆花，n种花，第i种最多a[i]盆，共摆m盆、按种类顺序，方案数 mod 1000007
// 逆序写法
int flowersReverse(int n, int m, const int a[]) {
    const int MODF = 1000007;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--)
            for (int t = 1; t <= a[i] && t <= j; t++) // 第i种花摆t盆
                dp[j] = (dp[j] + dp[j - t]) % MODF;
    }
    return dp[m];
}

// 完全背包：J19T3纪念品，每天把钱当成背包容量，“今天买、明天卖”的利润做完全背包
const int MAXV = 10005;
int dp2[MAXV];
int souvenir(int T, int N, int M, int price[][105]) {
    // price[t][i] 第t天第i种的价格
    for (int t = 1; t < T; t++) {
        for (int j = 0; j <= M; j++) dp2[j] = 0;
        for (int i = 1; i <= N; i++) {
            int cost = price[t][i], gain = price[t + 1][i] - price[t][i];
            if (gain <= 0) continue; // 不赚钱的不买
            for (int j = cost; j <= M; j++)
                dp2[j] = max(dp2[j], dp2[j - cost] + gain);
        }
        M += dp2[M];
    }
    return M;
}

int main() {
    return 0;
}