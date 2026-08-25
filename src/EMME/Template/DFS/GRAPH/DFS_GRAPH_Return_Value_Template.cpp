//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[105];
bool vis[105];
long long cnt = 0;

int dfsCount(int u) {
    vis[u] = true;
    int cnt = 1;
    for (int v : g[u])
        if (!vis[v]) cnt += dfsCount(v);
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, v, u; i <= m; i++) {
        cin >> v >> u;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsCount(1);
    return 0;
}