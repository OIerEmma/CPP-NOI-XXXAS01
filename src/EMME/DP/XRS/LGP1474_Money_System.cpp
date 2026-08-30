//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++) cin >> coins[i];
    vector<long long> dp(a + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = coins[i]; j <= a; j++)
            dp[j] += dp[j - coins[i]];
    cout << dp[a] << endl;
    return 0;
}