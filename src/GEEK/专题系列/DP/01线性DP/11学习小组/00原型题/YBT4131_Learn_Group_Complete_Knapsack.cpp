//
// Created by Geek.Kwok on 6/25/26.
//
#include <bits/stdc++.h>
using namespace std;

const int NEG_INF = -1e9;

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入数据
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 核心算法
    // 初始化
    vector<int> dp(n + 1, NEG_INF);
    dp[0] = 0;
    // 计算顺序
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
          if (dp[j - i] != NEG_INF) dp[j] = max(dp[j], dp[j - i] + a[i]);

    // 输出结果：从题意知道结果其实一定存在，全部学生组成一个学习小组
    if (dp[n] != NEG_INF) cout << dp[n] << endl;
    else cout << -1 << endl;

    return 0;
}

/**

题目链接：https://ybt.ssoier.cn/problem_show.php?pid=4131

问题初步分析：
- 因为题意是说把n个学生分成多个学习小组，那么各个学习小组人数的总和为n，所以该问题可以看成在一系列的学习小组中，选择某些小组使其人数总和恰好等于n，求此时的最大积极度
- 故此问题可以看成恰好型完全背包问题。套模板写即可
- 详见上述源代码

完全背包恰好型：

问题分析：这个问题也可以使用“完全背包恰好型”模型来解题
物品i：由i个学生组成的学习小组i
物品i重量w[i]：小组i的人数i
物品i价值v[i]：小组i的总积极度a[i]
背包容量：n
问题转化：物品总重量恰好为n的最大价值

 */