//
// Created by Geek.Kwok on 2026/10/2.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_live_rewards.in", "r", stdin);
    // freopen("g_live_rewards.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n, w, scores[601] = {};
    cin >> n >> w;
    for (int i = 1, s, r; i <= n; i++) {
        cin >> s, scores[s]++;
        r = max(1, i * w / 100);
        for (int j = 600, nums = 0; j >= 0; j--) {
            nums += scores[j];
            if (nums >= r) { cout << j << " "; break; }
        }
    }
    return 0;
}