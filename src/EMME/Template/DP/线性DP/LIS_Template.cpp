//
// Created by Emme.Kwok on 2026/7/18.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 状态：dp[i]代表以第i个数字为结尾，最长上升子序列（LIS）的长度
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}