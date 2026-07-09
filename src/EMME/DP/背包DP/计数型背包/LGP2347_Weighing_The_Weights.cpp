//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

const int n = 6, N = 1000;
const int w[] = {1, 2, 3, 5, 10, 20};

int main() {
    int cnt = 0, sum = 0;
    vector<int> c(N);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) c[cnt++] = w[i], sum += w[i];
    }
    // 状态：dp[j]代表前若干个砝码可以凑出重量j的方案数
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < cnt; i++)
        for (int j = sum; j >= c[i]; j--)
            dp[j] += dp[j - c[i]];
    long long ans = 0;
    for (int i = 1; i <= sum; i++) if (dp[i]) ans++;
    cout << "Total=" << ans << endl;
    return 0;
}