//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

int n, m, a, b;
long long dist[200005];
vector<int> g[200005];

bool bfs(int start) {
    for (int i = 0; i < n; i++) dist[i] = -1;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == b) return true;
        for (int v : g[now])
            if (dist[v] == -1) {
                dist[v] = dist[now] + 1;
                q.push(v);
            }
    }
    return false;
}

int main() {
    cin >> n >> m >> a >> b;
    vector<long long> v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    if (bfs(a)) cout << v[b] - v[a] + dist[b] << endl;
    else cout << "No solution" << endl;
    return 0;
}