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
    sort(c.begin(), c.end());

    // 初始化
    int ans = 1;
    vector<int> dp(n, 1);
    // 计算顺序
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (c[j][1] <= c[i][1])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    // 返回结果
    cout << ans << endl;
    return 0;
}

/**
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2

2 4 9 10 15 17 22
6 2 8 3  12 17 4

 */