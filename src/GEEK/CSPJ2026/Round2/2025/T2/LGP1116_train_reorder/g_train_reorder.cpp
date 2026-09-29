//
// Created by Geek.Kwok on 2026/9/29.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_train_reorder.in", "r", stdin);
    // freopen("g_train_reorder.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, ans = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) ans++;
    cout << ans << endl;
    return 0;
}