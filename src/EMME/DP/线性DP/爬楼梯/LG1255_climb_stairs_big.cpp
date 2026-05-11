//
// Created by Emme.Kwok on 2026/5/10.
//
#include<iostream>
#include<vector>
using namespace std;

void addBIG(vector<int> a, vector<int> b, vector<int>& c) {
    int jin = 0;
    c[0] = max(a[0], b[0]);
    // cout << a[0] << " " << b[0] << " " << c[0] << endl;
    for (int i = 1; i <= c[0]; i++) {
        c[i] = a[i] + b[i] + jin;
        jin = c[i] / 10;
        c[i] %= 10;
        // cout << c[i] << " " << jin << endl;
    }
    if (jin > 0) {
        c[0]++;
        c[c[0]] = jin;
    }
}

// void printBIG(vector<int> a) {
//     for (int i = a[0]; i >= 1; i--) cout << a[i];
// }

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(2000, 0));
    dp[0][1] = dp[1][1] = dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        addBIG(dp[i - 1], dp[i - 2], dp[i]);
        // printBIG(dp[i]);
    }
    for (int i = dp[n][0]; i >= 1; i--) cout << dp[n][i];
    return 0;
}