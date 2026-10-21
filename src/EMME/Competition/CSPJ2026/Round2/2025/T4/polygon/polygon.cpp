//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
int a[5005];
long long dp[5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0] = 1;
    long long pow2 = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        long long res = 0;
        for (int j = 0; j <= a[i]; j++) res = (res + dp[j]) % MOD;
        ans = (ans + pow2 - res + MOD) % MOD;
        for (int j = a[n]; j >= a[i]; j--) dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        pow2 = pow2 * 2 % MOD;
    }
    cout << ans << endl;
    return 0;
}