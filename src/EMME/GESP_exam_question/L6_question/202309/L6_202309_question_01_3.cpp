//
// Created by Emme.Kwok on 2026/5/6.
//
#include<iostream>
#include<vector>
using namespace std;

int n, L;
const int INF = 1e9;

int main() {
    cin >> n >> L;
    vector<int> c(n), l(n);
    for (int i = 0; i < n; i++) cin >> c[i] >> l[i];
    vector<int> dp(L + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = L; j >= 0; j--) {
            if (dp[max(j - l[i], 0)] != INF)
                dp[j] = min(dp[max(j - l[i], 0)] + c[i], dp[j]);
        }
    }
    if (dp[L] != INF) cout << dp[L] << endl;
    else cout << "no solution" << endl;
    return 0;
}