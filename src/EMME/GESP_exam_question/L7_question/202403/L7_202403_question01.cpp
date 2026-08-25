//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int color[100005];
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
    memset(color, -1, sizeof color);
    int minB = 0;
    for (int i = 1; i <= n; i++)
        if (color[i] == -1) {
            cnt[0] = cnt[1] = 0;
            dfs(i, 0);
            minB += min(cnt[0], cnt[1]);
        }
    cout << minB << " " << n - minB << endl;
    return 0;
}