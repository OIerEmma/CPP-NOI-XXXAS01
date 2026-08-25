//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int color[105];
int cnt[2];

void dfs(int u, int c) {
    color[u] = c;
    cnt[c]++;
    for (int v : g[u])
        if (color[v] == -1) dfs(v, !c);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return 0;
}