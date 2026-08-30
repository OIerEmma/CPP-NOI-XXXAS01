//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

vector<long long> g[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long c = g[i].size();
        ans += c * (c - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}