//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
bool vis[100005];

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for (int v : g[u])
        if (!vis[v]) dfs(v);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int v : g[now])
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    dfs(1);
    cout << endl;
    memset(vis, false, sizeof vis);
    bfs(1);
    return 0;
}