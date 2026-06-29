//
// Created by Geek.Kwok on 6/24/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;
vector<int> w(400);

// 完全背包版本
int main2() {
  int cnt, n;
  cin >> n;
  for (cnt = 1; cnt * cnt <= n; cnt++) w[cnt-1] = cnt * cnt; // 0-based

  // 核心算法
  // 状态：DP[i][j] 前i个完全平方数中，选取某些数之和恰好为j，选择数的最小个数
  // 初始化
  vector<vector<int>> dp(cnt + 1, vector<int>(n + 1, INF)); // 初始不可达
  for (int i = 0; i < cnt; i++) dp[i][0] = 0; // 和为0不需要选择任何数
  // 计算顺序
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j <= n; j++) {
      dp[i + 1][j] = dp[i][j]; // 不选
      if (j >= w[i]) dp[i + 1][j] = min(dp[i + 1][j], dp[i + 1][j - w[i]] + 1); // 选
    }

  // 结果：从题意知道结果其实一定存在，即用1来组成
  if (dp[cnt][n] != INF) cout << dp[cnt][n] << endl;
  else cout << -1 << endl;
  return 0;
}

// 完全背包一维优化版本
int main() {
  int cnt, n;
  cin >> n;
  for (cnt = 1; cnt * cnt <= n; cnt++) w[cnt - 1] = cnt * cnt; // 0-based

  // 核心算法
  // 状态：DP[j] 前i个完全平方数中，选取某些数之和恰好为j，选择数的最小个数
  // 初始化
  vector<int> dp(n + 1, INF); // 初始不可达
  dp[0] = 0; // 和为0不需要选择任何数
  // 计算顺序
  for (int i = 0; i < cnt; i++)
    for (int j = w[i]; j <= n; j++)
      dp[j] = min(dp[j], dp[j - w[i]] + 1); // 不选和选

  // 结果：从题意知道结果其实一定存在，比如全部用n个1^2可以组成n
  if (dp[n] != INF) cout << dp[n] << endl;
  else cout << -1 << endl;
  return 0;
}

/**

题目链接：https://ybt.ssoier.cn/problem_show.php?pid=4083

问题初步分析：
- 因为题意要求某些数的完全平方数之和为n，所以该问题可以看成在一系列的完全平方数中，选择某些数使其和恰好等于n，求此时的最小拆分数
- 故此问题可以看成恰好型完全背包问题。套模板写即可
- 详见上述源代码

完全背包恰好型：
---
问题分析：这个问题也可以使用“完全背包恰好型”模型来解题
物品i：由i*i得到的数字
物品i重量w[i]：数字i*i的值
物品i价值v[i]：1
背包容量：n
问题转化：物品总重量恰好为n的最小拆分数

*/