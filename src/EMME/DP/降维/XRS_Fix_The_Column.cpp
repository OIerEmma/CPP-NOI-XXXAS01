//
// Created by Emme.Kwok on 2026/8/25.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEG = -1e15;

int main() {
    int n, S = 0;
    cin >> n;
    vector<int> h(n), v(n);
    for (int i = 0; i < n; i++) cin >> h[i], S += h[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) S += h[i];
    int SZ = 2 * S + 1;
    vector<long long> dp(SZ, NEG);
    dp[S] = 0;
    for (int i = 0; i < n; i++) {
        vector<long long> ndp = dp;
        for (int j = 0; j < SZ; j++) {
            if (dp[j] == NEG) continue;
            int jl = j + h[i], jr = j - h[i];;
            if (jl < SZ) if (dp[j] + v[i] > ndp[jl]) ndp[jl] = dp[j] + v[i];
            if (jr >= 0) if (dp[j] + v[i] > ndp[jr]) ndp[jr] = dp[j] + v[i];
        }
        dp.swap(ndp);
    }
    cout << max(0LL, dp[S]) << endl;
    return 0;
}