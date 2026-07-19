//
// Created by Emme.Kwok on 2026/7/17.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 2, 0);   // 第 5 步：a[0]=a[n+1]=0 作哨兵
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 状态：dp[i][j] = 删空区间 [i,j] 的最大总分
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0)); // 第 5 步：初值 0

    for (int len = 1; len <= n; len++) {           // 第 6 步：len 从小到大（从 1 起）
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {         // 第 3、4 步（逆向/拉）：最后删谁（k <= j）
                long long left  = (k - 1 >= i) ? dp[i][k - 1] : 0;
                long long right = (k + 1 <= j) ? dp[k + 1][j] : 0;
                dp[i][j] = max(dp[i][j], left + right + (a[i - 1] + a[k] +  a[j + 1]) * (a[i - 1] + a[k] +  a[j + 1]));
            }
        }
    }

    cout << dp[1][n] << endl;                      // 第 7 步：答案在 dp[0][n + 1]
    return 0;
}