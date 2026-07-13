//
// Created by Emme.Kwok on 2026/7/12.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int n = (int)obstacleGrid.size(), m = (int)obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            if (!obstacleGrid[i - 1][0]) dp[i][1] = 1;
            else break;
        }
        for (int i = 1; i <= m; i++) {
            if (!obstacleGrid[0][i - 1]) dp[1][i] = 1;
            else break;
        }
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= m; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return dp[n][m];
    }
};

int main() {
    Solution* s = new Solution();
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s->uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}