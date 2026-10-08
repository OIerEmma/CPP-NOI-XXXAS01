//
// Created by Geek.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

int w[10005], t[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int idx = -1, minn = 1e9;
        for (int j = 1; j <= m; j++)
            if (minn > t[j]) {
                idx = j;
                minn = t[j];
            }
        t[idx] += w[i];
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) ans = max(ans, t[i]);
    cout << ans << endl;
    return 0;
}