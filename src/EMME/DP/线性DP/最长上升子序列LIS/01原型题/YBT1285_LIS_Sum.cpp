//
// Created by Emme.Kwok on 2026/5/21.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i]; // 输入
    vector<int> dp(n + 1); // 初始化条件
    for (int i = 0; i < n; i++) dp[i] = a[i];
    int ans = 0;
    // 计算顺序
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) // 比前一个大才可以接到后面去
                dp[i] = max(dp[i], dp[j] + a[i]); // 状态转移方程
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}