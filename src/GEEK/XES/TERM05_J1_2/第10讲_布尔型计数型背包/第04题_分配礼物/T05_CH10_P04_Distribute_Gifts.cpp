//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;  // 礼物的累计总价值
    for (int i = 0; i < n; i++) cin >> a[i], s += a[i];
    // 状态：dp[i]代表总价值为i的情况是否可分出
    // 初始化
    int total = s; s /= 2;
    vector<bool> dp(s + 1, false);
    dp[0] = true;
    // 顺序
    for (int i = 0; i < n; i++)
        for (int j = s; j >= a[i]; j--) // 逆序，一维01背包
            dp[j] = dp[j] || dp[j - a[i]];
    // 答案：j 为较小的一堆，total - j 为较大的一堆
    for (int j = s; j >= 0; j--) if (dp[j]) cout << total - j - j << endl, exit(0);
    return 0;
}