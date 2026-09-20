//
// Created by Geek.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> g[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    for (int v : g[x]) if (!vis[v]) dfs(v);
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
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            dfs(i);
            ans++;
        }
    cout << ans - 1 << endl;
    return 0;
}