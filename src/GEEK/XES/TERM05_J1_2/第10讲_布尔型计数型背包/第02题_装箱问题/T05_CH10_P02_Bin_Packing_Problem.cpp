//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 状态：dp[i]代表重量i是否可以装出
    // 初始化
    vector<bool> dp(V + 1, false);
    dp[0] = true;
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = V; j >= a[i]; j--)  // 布尔型01背包
            dp[j] = dp[j] || dp[j - a[i]];
    // 答案
    for (int j = V; j >= 0; j--) if (dp[j]) cout << V - j << endl, exit(0);
    return 0;
}