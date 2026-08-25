//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
bool vis[100005];

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) if (!vis[v]) dfs(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1 << endl;
    return 0;
}