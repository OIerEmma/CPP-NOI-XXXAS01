//
// Created by Geek.Kwok on 2026/9/9.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const long long INF = 4000000000000000000LL;   // 4e18，大于 5000 * 1e9

struct RawEdge {
    int u, v, w, b, id;
};

bool cmpByB(const RawEdge &x, const RawEdge &y) {
    return x.b < y.b;
}

int n, m;
vector<pair<int, pair<long long, int> > > g[MAXN];
// g[u][i] = (v, (w, 边编号))

long long d1[MAXN], dn[MAXN];

void dijkstra(int s, int skip, long long dist[]) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int> >,
                   greater<pair<long long, int> > > q;
    q.push(make_pair(0LL, s));
    while (!q.empty()) {
        long long d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d != dist[u]) continue;            // 过期票
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].first;
            long long w = g[u][i].second.first;
            int id = g[u][i].second.second;
            if (id == skip) continue;          // 免费边：不走、不付钱
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    if (n == 1) {                              // 起点即终点
        // cout << 0 << endl;
        printf("0\n");
        return 0;
    }
    vector<RawEdge> es(m);
    for (int i = 0; i < m; i++) {
        // cin >> es[i].u >> es[i].v >> es[i].w >> es[i].b;
        scanf("%d%d%d%d", &es[i].u, &es[i].v, &es[i].w, &es[i].b);
        es[i].id = i;
    }
    sort(es.begin(), es.end(), cmpByB);

    long long ans = INF;
    int i = 0;
    while (i < m) {
        int j = i;
        while (j < m && es[j].b == es[i].b) j++;
        for (int k = i; k < j; k++) { // 本批边全部加入
            int u = es[k].u, v = es[k].v, id = es[k].id;
            long long w = es[k].w;
            g[u].push_back(make_pair(v, make_pair(w, id)));
            g[v].push_back(make_pair(u, make_pair(w, id)));
        }
        for (int k = i; k < j; k++) { // 本批每一条都当一次免费边
            int u = es[k].u, v = es[k].v, skip = es[k].id;
            dijkstra(1, skip, d1);
            dijkstra(n, skip, dn);
            if (d1[u] < INF && dn[v] < INF) ans = min(ans, d1[u] + dn[v]);
            if (d1[v] < INF && dn[u] < INF) ans = min(ans, d1[v] + dn[u]);
        }
        i = j;
    }
    if (ans >= INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}