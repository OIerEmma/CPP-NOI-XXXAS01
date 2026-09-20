//
// Created by Emme.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1), d(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i], d[i] = a[i] - a[i - 1];
    int l, r, v;
    while (m--) {
        cin >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }
    vector<long long> res(n + 1);
    long long ans = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) res[i] = res[i - 1] + d[i], ans = min(ans, res[i]);
    cout << ans << "\n";
    return 0;
}
