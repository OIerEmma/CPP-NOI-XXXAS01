//
// Created by Geek.Kwok on 2026/9/29.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_seat.in", "r", stdin);
    // freopen("g_seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, m; cin >> n >> m;
    vector<int> a(n * m + 1, 0);
    for (int i = 0; i < n * m; i++) cin >> a[i];
    int R = a[0], pos = -1;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n * m; i++) if (a[i] == R) { pos = i; break; }
    int c = pos / n + 1, r = pos % n + 1;
    if (c % 2 == 0) r = n + 1 - r;
    cout << c << " " << r << endl;
    return 0;
}