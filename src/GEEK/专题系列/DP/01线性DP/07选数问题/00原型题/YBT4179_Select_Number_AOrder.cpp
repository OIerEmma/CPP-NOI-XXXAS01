//
// Created by Geek.Kwok on 5/20/26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), dp(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // 状态定义：dp[i] 表示前 i 个数中的选数的最大值
    // 优化：跳转表
    vector<vector<int>> jump_to(n);
    for (int i = 0; i < n; i++)
        if (b[i])
            for (int j = i + b[i]; j < n; j++)
                jump_to[j].push_back(i);
    // 初始化
    for (int i = 0; i < n; i++) dp[i] = a[i];
    // 计算顺序
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        for (int j: jump_to[i])
            dp[i] = max(dp[i], dp[j] + a[i]);
    }
    // 返回结果
    cout << dp[n - 1] << endl;
    return 0;
}

/*
题目分析与dp设计：
---
样例：$$n = 4$$，$$a = [3, 1, 2, 4]$$，$$b = [1, 2, 1, 1]$$。答案为 $$8$$（选下标 1 和 4，$$a[1]+a[4]=3+4=7$$？稍后手算验证给出确切值）。

a[] = {3,1,2,4}
b[] = {1,2,1,1}
1.划分阶段：针对每个数字，做选择决策，就是一个阶段。在阶段内可以选择该数字，并跳转至下一个大于等于 pi + b[pi] 数字，或者不选择该数字，进而进入下一个 pi + 1 数字；然后进入下一个阶段，开始新一轮的选择决策。
2.状态定义：dp[i] 表示前 i 个数中的选数的最大值 max
3.分析决策：问自己3个问题
3.1 有哪些选择？决策允许集合。 站点某个i位置，可以：
  - 选择 a[i] 并跳转至大于等于 j = i + b[i]，再次做选择；此时 dp[j] = max { dp[j], dp[i] + a[i] } , i + b[i] <= j < n
  - 不选择 a[i]，则直接进入 a[i+1]，再次做选择；此时 dp[i + 1] = max { dp[i + 1], dp[i] }
3.2 从哪转移？决策转移过程。从拉取视角，站在某个i位置，可以：
  - 不选择来源节点 即可以从 j = i-1 节点转移而来，dp[i] = max { dp[i], dp[j] } j = i - 1
  - 选择来源节点 即可以从 0<=j<i 中的任意一个满足 j + b[j] <= i 的节点转移而来，dp[i] = max { dp[i], dp[j] + a[i] } 0<=j<i & j + b[j] <= i
3.3 dp值怎么变？状态结果计算。站在某个i位置：
  - 不选择来源节点：dp[i] = max { dp[i], dp[j] } j = i - 1
  - 选择来源节点：dp[i] = max { dp[i], dp[j] + a[i] } 0<=j<i && j + b[j] <= i
4.写出状态转移方程：
dp[i] = max { dp[i], dp[j] } , j = i - 1
dp[i] = max { dp[i], dp[j] + a[i] } , 0<=j<i && j + b[j] <= i
5.确定初始条件
问自己：最小的不需要推导就能确定答案的状态是什么？
每个数自己独立能形成一个最大和 for (int i = 0; i < n; i++) dp[i] = a[i]
6.确定计算顺序
问自己（核心原则）：计算dp[i]][j]时，依赖的dp值都已经计算好了
i 从小到大
7.确定返回结果
问自己：最终答案在dp数组的哪个位置？取决于状态定义的方式
dp[n-1]
*/