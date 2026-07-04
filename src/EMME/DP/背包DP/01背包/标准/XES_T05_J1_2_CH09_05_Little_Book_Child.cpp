//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, r;
    cin >> n >> m >> k >> r;
    vector<int> t(n), h(m), s(m);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < m; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> s[i];
    // 状态：dp[j]代表耗时不超过j时的最大分数
    vector<int> dp(r + 1, 0);
    for (int i = 0; i < m; i++)
        for (int j = r; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    for (int i = 0; i <= r; i++)
        if (dp[i] >= k) { r -= i; break; }
    sort(t.begin(), t.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) if (r >= t[i]) r -= t[i], cnt++;
    cout << cnt << endl;
    return 0;
}