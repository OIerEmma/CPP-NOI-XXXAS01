//
// Created by Emme.Kwok on 2026/6/23.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m >> s;
    // 定义状态：DP[i] 代表前i个字符的最大得分
    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; ; j++) {
            if (i - 3 * j < 0 ||
                s.substr(i - 3 * j, 3) != "abc") break;
            dp[i] = max(dp[i], dp[i - 3 * j] + a[j]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
/*
1.划分阶段
    针对当前一个字母，将它划分到前面一个，或者新开一个字符串
2.定义状态
    DP[i] 代表前i个字符的最大得分
3.分析决策
    1）有哪些选择？决策允许集合：针对第i个字符，选或不选
    2）从哪里转移？状态转移过程：不选：i - 1，选：i - 3j，i - 3j >= 0，j >= 1
    3）dp值怎么变？状态结果计算：DP[i] = max(DP[i - 1], DP[i - 3j] + a[j])
4.状态转移方程
    DP[i] = max{DP[i - 1], DP[i - 3j] + a[j]}, i - 3j >= 0 && j >= 1
5.确定初始条件
    DP[0] = 0
6.确定计算顺序
    从小到大
7.确定返回结果
    DP[m]
*/