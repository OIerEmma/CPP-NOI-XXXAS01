//
// Created by Emme.Kwok on 2026/7/8.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, v, n;
    cin >> m >> v >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(m + 1, vector<int>(v + 1, 0));
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int x = m; x >= a[i]; x--)
            for (int y = v; y >= b[i]; y--)
                if (dp[x - a[i]][y - b[i]] + c[i] > dp[x][y]) {
                    dp[x][y] = dp[x - a[i]][y - b[i]] + c[i];
                    if (!flag) ans.push_back(i + 1), flag = true;
                }
    }
    cout << dp[m][v] << endl;
    for (int i : ans) cout << i << " ";
    return 0;
}