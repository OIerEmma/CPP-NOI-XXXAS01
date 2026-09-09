//
// Created by Geek.Kwok on 2026/9/9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<int, long long> cnt;
    int v = 0; long long ans = 0;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        v ^= 1 << (s[i] - 'a');
        ans += cnt[v]; // pre[l-1] = pre[r] - 0
        cnt[v]++;
    }
    cout << ans << '\n';
    return 0;
}