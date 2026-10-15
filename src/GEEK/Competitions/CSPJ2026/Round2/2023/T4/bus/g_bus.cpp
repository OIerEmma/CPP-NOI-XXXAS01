//
// Created by Geek.Kwok on 2026/10/15.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10005, MAXK = 105;
struct Edge { int to, open; };
vector<Edge> g[MAXN];
int dist[MAXN][MAXK]; // dist[地点][余数] = 该状态的最早时刻
bool done[MAXN][MAXK]; // done[地点][余数] 这个(地点,余数) 是否已经盖章

int main() {
  // freopen("g_bus.in", "r", stdin); freopen("g_bus.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  // 下面开始写本题
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0, u, v, a; i < m; i++) {
    cin >> u >> v >> a;
    g[u].push_back({v, a});
  }
  memset(dist, 0x3f, sizeof(dist));
  // 小根堆：先弹出时刻更小的记录
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[1][0] = 0; // 最早一班车：0 时刻在入口, 余数为 0
  pq.push({0, 1}); // 堆里放 {时刻, 地点}，余数由时刻 % k还原
  while (!pq.empty()) {
    int t = pq.top().first, u = pq.top().second;
    pq.pop();
    int r = t % k;
    if (done[u][r]) continue; // 旧记录：这个余数已经用更早的时刻扩展过则丢弃
    done[u][r] = true; // 第一次弹出即定稿盖章
    for (auto &e : g[u]) {
      int nt = t;
      if (nt < e.open) nt += (e.open - nt + k - 1) / k * k; // 路还没有开放时则只允许加上 k 的倍数（即改坐更晚的班车）
      nt += 1; // 走路本身用时1个单位，余数也因此+1
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