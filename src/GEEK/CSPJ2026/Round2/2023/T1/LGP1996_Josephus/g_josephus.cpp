//
// Created by Geek.Kwok on 2026/9/21.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_josephus.in", "r", stdin);
    // freopen("g_josephus.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    vector<bool> j(110, false);
    int n, m, pos = 0, cnt = 0;
    cin >> n >> m;
    while (cnt < n) {
        int c = 0;
        while (c < m) {
            pos = pos == n ? 1 : (pos + 1) % (n + 1);
            if (!j[pos]) c++;
        }
        j[pos] = true; cnt++;
        cout << pos << " ";
    }
    return 0;
}