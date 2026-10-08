//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_road.in", "r", stdin);
    // freopen("g_road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, d; cin >> n >> d;
    vector<int> v(n), a(n);
    for (int i = 0; i < n - 1; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0, dist = 0, fuel = 0;
    for (int i = 0, j = 1; j < n; j++) {
        dist += v[j-1];
        if (a[i] > a[j] || j == n - 1) {
            long long oil = (dist - fuel - 1) / d + 1;
            ans += 1LL * oil * a[i];
            fuel += oil * d - dist;
            dist = 0;
            i = j;
        }
    }
    cout << ans << endl;
    return 0;
}