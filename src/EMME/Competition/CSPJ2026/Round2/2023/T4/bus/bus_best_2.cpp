//
// Created by Emme.Kwok on 2026/10/14.
//
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, N = 10005, K = 105;
struct Edge { int to, open; };
vector<Edge> g[N];
int dist[N][K];
bool done[N][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1, u, v, a; i <= m; i++) {
        cin >> u >> v >> a;
        g[u].push_back({v, a});
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1][0] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int t = pq.top().first, u = pq.top().second, r = t % k; pq.pop();
        if (done[u][r]) continue;
        done[u][r] = true;
        for (auto e : g[u]) {
            int nt = t;
            if (nt < e.open) nt += (e.open - nt + k - 1) / k * k;
            nt++;
            int nr = nt % k;
            if (nt < dist[e.to][nr]) {
                dist[e.to][nr] = nt;
                pq.push({nt, e.to});
            }
        }
    }
    cout << (dist[n][0] == INF ? -1 : dist[n][0]) << "\n";
    return 0;
}