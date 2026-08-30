//
// Created by Emme.Kwok on 2026/8/26.
//
#include<bits/stdc++.h>
using namespace std;

int n, m;
int dist[2005];
vector<int> g[2005];

int bfs(int start) {
    for (int i = 1; i <= n; i++) dist[i] = -1;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int ans = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans = max(ans, dist[now]);
        for (int v : g[now])
            if (dist[v] == -1) {
                dist[v] = dist[now] + 1;
                q.push(v);
            }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 1, best = 1e9, cur;
    for (int i = 1; i <= n; i++) {
        cur = bfs(i);
        if (cur < best) best = cur, ans = i;
    }
    cout << ans << endl;
    return 0;
}