//
// Created by Geek.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, a, b;
long long dist[N];

bool bfs(int start) {
    for (int i = 0; i < n; i++) dist[i] = -1;
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
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
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
    }
    if (bfs(a)) cout << v[b] - v[a] + dist[b] << endl;
    else cout << "No solution" << endl;
    return 0;
}