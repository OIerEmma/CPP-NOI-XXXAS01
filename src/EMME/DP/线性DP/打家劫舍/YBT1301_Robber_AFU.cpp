//
// Created by Emme.Kwok on 2026/5/13.
//
#include<iostream>
using namespace std;

int a[100005], dp[100005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        dp[0] = 0, dp[1] = a[1];
        for (int i = 1; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        cout << dp[n] << endl;
    }
    return 0;
}