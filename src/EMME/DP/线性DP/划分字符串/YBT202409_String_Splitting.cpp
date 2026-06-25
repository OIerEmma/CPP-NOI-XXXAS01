//
// Created by Emme.Kwok on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 定义状态：dp[i] 代表前i个字符经过划分后能获得价值的最大值
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int mask = 0;
        dp[i] = dp[i - 1] + a[1];
        mask |= 1 << (s[i - 1] - 'a');
        for (int j = 1; j < i; j++) {
            if (mask & 1 << (s[i - j - 1] - 'a')) break;
            dp[i] = max(dp[i - j - 1] + a[j + 1], dp[i]);
            mask |= 1 << (s[i - j - 1] - 'a');
        }
    }
    cout << dp[n] << endl;
    return 0;
}
/*
1.划分阶段：这个问题可以划分成哪些阶段？每个阶段在做什么决定？
    从左到右扫描字符，每个阶段对应1个字符
    假设当前站在第i个字符，往前回溯j个字符，如果从j到i没找到重复字符那么dp[i] = dp[i - j] + a[j]
2.定义状态：dp[i] 或 dp[i][j] 代表什么？存储的是最大值，最小值还是方案数
    dp[i] 代表前i个字符经过划分后能获得价值的最大值
3.分析决策
    1.有哪些选择？决策允许集合：
        假设当前在第i个字符，看此字符后面j个字符直到有重复的字符
    2.从哪里转移？状态转移过程：
        假设当前在第i个字符，看字符前j个字符直到有重复的字符
    3.dp值怎么变？状态结果计算：
        没有重复字符：dp[i] = max{dp[i - j] + a[j]}, 1 <= j <= i - 1
        有重复字符：不需要计算，结束
4.状态转移方程 dp[i] = max{dp[i - j] + a[j]}, 1 <= j < i, s[j ~ i]唯一(mask)
5.确定初始条件：最小的、不需要推导就能确定答案的状态是什么？
    dp[0] = 0, dp[i] = dp[i - 1] + a[1]
6.确定计算顺序：计算dp[i]时，它依赖的dp值应该已经计算好了？从小到大
7.确定返回结果：最终答案存在dp数组的哪个位置？这取决于状态定义的方式 dp[n]
*/