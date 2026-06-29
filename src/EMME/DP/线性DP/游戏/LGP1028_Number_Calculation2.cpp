//
// Created by Emme.Kwok on 2026/6/17.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i / 2; j++)
            dp[i] += dp[j];
    // for (int i = 1; i <= n; i++) cout << DP[i] << endl;
    cout << dp[n] << endl;
    return 0;
}