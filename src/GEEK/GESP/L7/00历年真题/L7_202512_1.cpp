//
// Created by Geek.Kwok on 2026/8/26.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
vector<int> g[MAXN];
int dist[MAXN];

// BFS求最短路：返回 s 的偏心率
int bfsEcc(int s, int n) {
  for (int i = 1; i <= n; i++) dist[i] = -1; // ⚠️ 每次都要重置！
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  int mx = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (mx < dist[u]) mx = dist[u]; // 顺手记最大距离
    for (int v : g[u]) if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
  }
  return mx;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 1, best = bfsEcc(1, n);
  for (int i = 2; i <= n; i++) {
    int cur = bfsEcc(i, n);
    if (cur < best) { ans = i; best = cur; } // ⚠️ 严格小于 → 并列时自动保留编号最小
  }
  cout << ans << endl;
  return 0;
}