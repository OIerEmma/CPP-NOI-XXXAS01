//
// Created by Geek.Kwok on 2026/10/4.
//
#include<bits/stdc++.h>
using namespace std;

int cnt[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    int kinds = 0, t, k;
    for (int i = 1; i <= n; i++) {
        cin >> t >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            q.push({t, x});
            if (cnt[x]++ == 0) kinds++;
        }
        while (q.front().first <= t - 86400) {
            int x = q.front().second;
            q.pop();
            if (--cnt[x] == 0) kinds--;
        }
        cout << kinds << '\n';
    }
    return 0;
}