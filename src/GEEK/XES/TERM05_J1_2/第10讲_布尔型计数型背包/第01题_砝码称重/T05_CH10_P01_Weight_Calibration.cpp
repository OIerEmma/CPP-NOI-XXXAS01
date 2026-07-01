//
// Created by Geek.Kwok on 7/1/26.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int c[] = {1, 2, 3, 5, 10, 20};

int main() {
    vector<int> a(N);
    int cnt = 0, W = 0;  // cnt 物品数，W 累计总重量
    for (int x, i = 0; i < 6; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) a[cnt++] = c[i], W += c[i];
    }
    // 状态：dp[i]代表重量为i是否可以称出
    // 初始化
    vector<bool> dp(W + 1, false);
    dp[0] = true;
    // 顺序
    for (int i = 0; i < cnt; i++)
        for (int j = W; j >= a[i]; j--)  // 布尔型01背包
            dp[j] = dp[j] || dp[j - a[i]];
    // 答案
    int ans = 0;
    for (int i = 1; i <= W; i++) if (dp[i]) ans++;
    cout << ans << endl;
    return 0;
}