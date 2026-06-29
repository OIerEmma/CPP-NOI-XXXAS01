//
// Created by Emme.Kwok on 2026/5/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // 状态定义
        // DP[i][0] 前i个问题且第i个问题做的最高分
        // DP[i][1] 前i个问题且第i个问题不做的最高分
        int n = questions.size();
        if (n == 1) return questions[0][0];

        // 预处理：jump 表
        vector<vector<int>> jump_to(n + 1);
        for (int i = 1; i <= n; i++) {
            int next = i + questions[i - 1][1] + 1;
            if (next <= n) jump_to[next].push_back(i);
        }

        // 初始化
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // for (int i = 1; i <= n; i++) DP[i][0] = questions[i - 1][0];
        const int NEG_INF = -1e9;
        dp[0][0] = NEG_INF;
        dp[0][1] = 0;

        // 计算顺序
        for (int i = 1; i <= n; i++) {
            // 不做
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
            // 做
            int best_prev = 0;
            for (int j: jump_to[i]) {
                best_prev = max(best_prev, dp[j][0]);
            }
            dp[i][0] = best_prev + questions[i - 1][0];
        }

        // 返回结果
        return max(dp[n][0], dp[n][1]);
    }

    long long mostPoints2(vector<vector<int>>& questions) {
        int n = questions.size();
        // DP[i][0] / DP[i][1] 对应前 i 题的状态（0‑based 题目索引为 i-1）
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        // 跳跃来源表：jump_to[k] 存放所有能恰好跳到第 k 题（0‑based）的题号 j
        vector<vector<int>> jump_to(n);
        for (int j = 0; j < n; ++j) {
            int next = j + questions[j][1] + 1;   // 0‑based 下一题
            if (next < n) {
                jump_to[next].push_back(j);
            }
        }

        const long long NEG_INF = -1e18;
        dp[0][0] = 0;
        dp[0][1] = NEG_INF;   // 不存在“做了第 -1 题”

        for (int i = 1; i <= n; ++i) {
            // 不做第 i-1 题
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

            // 做第 i-1 题
            long long best_prev = dp[i-1][0];
            for (int j : jump_to[i - 1]) {
                best_prev = max(best_prev, dp[j + 1][1]);
            }
            int points = questions[i - 1][0];
            dp[i][1] = points + best_prev;
        }

        return max(dp[n][0], dp[n][1]);
    }
};

/**
[[3,2],[4,3],[4,4],[2,5]]
[[1,1],[2,2],[3,3],[4,4],[5,5]]
[[12,46],[78,19],[63,15],[79,62],[13,10]]
[[21,5],[92,3],[74,2],[39,4],[58,2],[5,5],[49,4],[65,3]]
 */

int main() {
    Solution *s = new Solution();
    // vector<vector<int>> nums({{3,2},{4,3},{4,4},{2,5}});
    // vector<vector<int>> nums({{1,1},{2,2},{3,3},{4,4},{5,5}});
    // vector<vector<int>> nums({{12,46},{78,19},{63,15},{79,62},{13,10}});
    vector<vector<int>> nums({{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}});
    cout << s->mostPoints(nums) << endl;
    // cout << s->mostPoints2(nums) << endl;
    return 0;
}