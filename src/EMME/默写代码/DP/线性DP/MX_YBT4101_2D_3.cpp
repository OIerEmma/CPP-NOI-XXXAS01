//
// Created by Emme.Kwok on 2026/9/11.
//
#include<bits/stdc++.h>
using namespace std;

const long long NEG = -1e18;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, P, Q, p, c;
        cin >> n >> P >> Q;
        vector<long long> dp(Q + 1, NEG);
        dp[0] = 0;
        while (n--) {
            cin >> p >> c;
            for (int i = Q; i >= c; i--)
                if (dp[i - c] != NEG) dp[i] = max(dp[i], dp[i - c] + p);
        }
        cout << dp[Q] << endl;
    }
    return 0;
}