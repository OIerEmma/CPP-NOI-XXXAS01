//
// Created by Emme.Kwok on 2026/8/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> a(n), b(n), v(n);
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, 0));
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> v[i];
    for (int i = 0; i < n; i++)
        for (int x = A; x >= a[i]; x--)
            for (int y = B; y >= b[i]; y--)
                dp[x][y] = max(dp[x][y], dp[x - a[i]][y - b[i]] + v[i]);
    cout << dp[A][B] << endl;
    return 0;
}