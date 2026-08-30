//
// Created by Emme.Kwok on 2026/8/30.
//
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[100005];
long long ans, res;

void dfs(int start, long long dist, int fa) {
    ans = max(ans, dist);
    for (auto v : g[start])
        if (v.first != fa) dfs(v.first, dist + v.second, start);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, u, v, l; i < n; i++) {
        cin >> u >> v >> l;
        g[u].push_back({v, l});
        g[v].push_back({u, l});
        res += l;
    }
    dfs(1, 0, 0);
    cout << res * 2 - ans << endl;
    return 0;
}