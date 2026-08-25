//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

bool vis[105];
vector<int> g[200005];

int dfs(int u) {
    vis[u] = true;
    int cnt = 1;
    for (int v : g[u]) cnt += dfs(v);
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int biggest = 0, blocks = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            blocks++;
            biggest = max(biggest, dfs(i));
        }
    return 0;
}