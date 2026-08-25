//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[105];
bool vis[105];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : g[u])
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, v, u; i <= m; i++) {
        cin >> v >> u;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    return 0;
}