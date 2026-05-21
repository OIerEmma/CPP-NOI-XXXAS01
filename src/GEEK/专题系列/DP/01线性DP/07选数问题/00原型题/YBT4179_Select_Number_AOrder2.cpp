//
// Created by Geek.Kwok on 5/20/26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<long long> a(n), dp(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // 状态定义：表示针对第i个数可选的前提下，前i个数中（不含i）的选数集合的最大累计和
    // 优化：跳转表(会超内存)
    vector<vector<int>> jump_to(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (j + b[j] <= i)
                jump_to[i].push_back(j);
    // 初始化
    // 计算顺序
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        for (int j: jump_to[i])
            dp[i] = max(dp[i], dp[j] + a[j]);
        // 不使用跳转表直接循环则会超时
        // for (int j = 0; j < i; j++)
        //     if (j + b[j] <= i) dp[i] = max(dp[i], dp[j] + a[j]);
        ans = max(ans, dp[i] + a[i]);
    }
    // 返回结果
    cout << ans << endl;
    return 0;
}

/*
题目分析与DP设计：
---
1.划分阶段：
    针对每个“可选择”的数字，做选择决策，就是一个阶段。在阶段内：
    - 可以选择该第i个数字并跳转，跳转至下一个大于等于i+b[i]数字；
    - 或者不选择该第i个数字，则传递至下一个i+1数字；
    然后进入下一个阶段，开始新一轮的选择决策。
2.状态定义：
    dp[i] 表示针对第i个数可选的前提下，前i个数中（不含i）的选数集合的最大累计和
3.分析决策：问自己3个问题
    3.1 有哪些选择？决策允许集合。【从递推视角，即从现在到未来】
    站点某个第i个数的位置，可以做选择：
        - 选择a[i]并跳转至大于等于j=i+b[i]的位置，dp[i + b[i]] = max { dp[i + b[i]], dp[i] + a[i] } , i + b[i] <= n
        - 不选择a[i]，则直接传递进入a[i+1]的位置，dp[i + 1] = max { dp[i + 1], dp[i] } , i + 1 <= n
    3.2 从哪转移？决策转移过程。【从拉取视角，即从过去到现在】
    站在某个第i个数的位置，可以追溯转移：
        - 从各个来源数字j并选择跳转的情况下，跳转至当前数字i，dp[i] = max { dp[i], dp[j] + a[j] } , j >= 1 && j + b[j] <= i
        - 从来源数字i-1并选择直接传递的情况下，传递至当前数字i，dp[i] = max { dp[i], dp[i - 1] } , 1 < i <= n
    3.3 dp值怎么变？状态结果计算。
    站在某个第i个数的位置，
        - 跳转：dp[i] = max { dp[i], dp[j] + a[j] } , j >= 1 && j + b[j] <= i
        - 传递：dp[i] = max { dp[i], dp[i - 1] } , 1 < i <= n
        - 同时，选项“选i作为当前最终选中下标”时，总价值为dp[i]+a[i]，应该实时更新全局最大值。
4.写出状态转移方程：
    dp[i] = max { dp[i], dp[j] + a[j] } , j >= 1 && j + b[j] <= i
    dp[i] = max { dp[i], dp[i - 1] } , 1 < i <= n
    ans = max(ans, dp[i] + a[i])
5.确定初始条件
    问自己：最小的、不需要推导就能确定答案的状态是什么？
    dp[1..n] = 0
    ans = 0
6.确定计算顺序
    问自己（核心原则）：计算dp[i]][j]时，依赖的dp值都必须已经计算好了
    i 从小到大
7.确定返回结果
    问自己：最终答案在dp数组的哪个位置？取决于状态定义的方式
    全局最大值在每次dp[i]+a[i]时更新。最终答案就是ans = max(dp[i]+a[i]), 1 <= i <= n。
    因为最后一个被选中的下标可以是任意一个合规的位置。
*/