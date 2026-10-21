//
// Created by Emme.Kwok on 2026/10/13.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int dist[100005];

void bfs() {
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int x : g[now])
            if (dist[x] == -1) q.push(x), dist[x] = dist[now] + 1;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    // for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    // cout << endl;
    for (int i = 1, a, l; i <= q; i++) {
        cin >> a >> l;
        // cout << dist[a] << endl;
        if (dist[a] == -1 || dist[a] % 2 != l % 2) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}