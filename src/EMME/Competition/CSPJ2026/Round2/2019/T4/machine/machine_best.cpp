//
// Created by Emme.Kwok on 2026/10/13.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100005;
vector<int> g[N];
int dist[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dist, INF, sizeof dist);
    queue<pair<int, int>> que;
    dist[1][0] = 0;
    que.push({1, 0});
    while (!que.empty()) {
        int u = que.front().first, par = que.front().second;
        que.pop();
        for (int v : g[u]) {
            int np = par ^ 1;
            if (dist[v][np] == INF) {
                dist[v][np] = dist[u][par] + 1;
                que.push({v, np});
            }
        }
    }
    bool iso = g[1].empty();
    while (q--) {
        int a, l;
        cin >> a >> l;
        cout << (!iso && dist[a][l % 2] <= l ? "Yes" : "No") << "\n";
    }
    return 0;
}