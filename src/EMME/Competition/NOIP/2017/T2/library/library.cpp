//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

int a[1005];
vector<pair<int, int>> g[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int t = a[i], j = 1, x = 1;
        while (t) {
            x *= 10; t /= 10;
            g[j].push_back({a[i] % x, a[i]});
            j++;
        }
    }
    int l, a;
    for (int i = 1; i <= q; i++) {
        cin >> l >> a;
        bool flag = false;
        for (int j = 0; j < g[l].size(); j++) {
            if (g[l][j].first == a) {
                flag = true;
                cout << g[l][j].second << "\n";
                break;
            }
            // cout << g[l][j].first << " " << g[l][j].second << endl;
        }
        if (!flag) cout << "-1\n";
    }
    return 0;
}