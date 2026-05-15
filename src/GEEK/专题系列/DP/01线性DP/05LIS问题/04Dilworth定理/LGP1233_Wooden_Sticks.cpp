//
// Created by Geek.Kwok on 5/15/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> c[i][0] >> c[i][1];
    sort(c.begin(), c.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    });

    // 初始化
    int ans = 1;
    vector<int> dp(n, 1);
    // 计算顺序
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            // 注意：求最长上升子序列（宽度相等时不算）
            if (c[j][1] < c[i][1])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    // 返回结果
    cout << ans << endl;
    return 0;
}

/**
5
4 9 5 2 2 1 3 5 1 4

4 5 2 3 1
9 2 1 5 4
 */