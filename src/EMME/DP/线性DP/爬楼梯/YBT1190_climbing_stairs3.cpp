//
// Created by Emme.Kwok on 2026/5/10.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (!n) break;
        vector<long long> dp(n + 2, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        cout << dp[n] << endl;
    }
    return 0;
}