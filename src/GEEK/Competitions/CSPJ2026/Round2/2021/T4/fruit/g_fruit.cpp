//
// Created by Geek.Kwok on 2026/10/21.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int typ[MAXN], pre[MAXN], nxt[MAXN]; // 数组模拟双向链表，串起还没被挑走的水果

int main() {
  // freopen("g_fruit.in", "r", stdin); freopen("g_fruit.out", "w", stdout);
  // ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d",  &typ[i]);
  for (int i = 0; i <= n; i++) pre[i] = i - 1, nxt[i] = i + 1;
  typ[0] = typ[n + 1] = -1; // 哨兵：和任何水果都不同类

  vector<int> heads; // 当前所有块头，从左到右
  for (int i = 1; i <= n; i++) if (i == 1 || typ[i] != typ[i - 1]) heads.push_back(i);
  while (!heads.empty()) {
    vector<int> cand;
    for (size_t i = 0; i < heads.size(); i++) {
      int h = heads[i];
      printf("%d%c", h, i + 1 == heads.size() ? '\n' : ' ');
      int r = nxt[h]; // r 为 h 的右邻居
      nxt[pre[h]] = r; // 把 h 从链表中删掉
      pre[r] = pre[h]; //
      if (typ[r] == typ[h]) cand.push_back(r); // 同一个块从 r 继续，r 是候选
    }
    heads.clear();
    for (int c : cand) if (typ[pre[c]] != typ[c]) heads.push_back(c); // 左邻居和 c 不同类，c才是真正的块头
  }
  return 0;
}