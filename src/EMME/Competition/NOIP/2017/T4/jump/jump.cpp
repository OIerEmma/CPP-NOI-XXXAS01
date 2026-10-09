//
// Created by Emme.Kwok on 2026/10/9.
//
#include <bits/stdc++.h>
using namespace std;

const int NEG = -1e9, R = 1e9 + 2000;
int n;
long long d, k;

bool check(long long g, vector<int> x, vector<int> s) {
    int l, r;
    if (g < d) l = d - g, r = d + g;
    else l = 1, r = d + g;
    vector<int> dp(n + 1, NEG);
    dp[0] = 0;
    int best = NEG;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == NEG) continue;
            if (x[i] - x[j] > r) continue;
            if (x[i] - x[j] < l) break;
            dp[i] = max(dp[i], dp[j] + s[i]);
        }
        best = max(best, dp[i]);
        if (best >= k) return true;
    }
    return best >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d >> k;
    vector<int> x(n + 1, 0), s(n + 1, 0);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> s[i];
        if (s[i] > 0) sum += s[i];
    }
    if (sum < k) cout << "-1\n", exit(0);
    long long l = 0, r = R;
    long long ans = -1;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (check(mid, x, s)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}