//
// Created by Emme.Kwok on 2026/5/16.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // 定义状态
        // dp[i] 代表从 0 到 i - 1 可以获得的最高分数(第i个不考虑)
        // 初始化
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        // dp[1] = questions[0][0];
        // 计算顺序 正序
        for (int i = 0; i < n; i++) {
            int next = i + questions[i][1] + 1;
            if (next > n) next = n;
            // 状态转移方程
            dp[i + 1] = max(dp[i + 1], dp[i]);
            dp[next] = max(dp[next], dp[i] + questions[i][0]);
        }
        // 返回结果
        return dp[n];
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