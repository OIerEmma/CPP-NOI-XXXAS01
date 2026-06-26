//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> col(2, 0);
vector<int> G[N], bel(N);

// DFS: 先序 + 参数
void dfs(int root, int color, int parent) {
  bel[root] = color;
  col[color]++;
  for (int child : G[root])
    if (child != parent)
      dfs(child, color ^ 1, root);
}

int main() {
  int n;
  cin >> n;
  // 建树：邻接表存树（未告知节点父子关系时）
  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  // 调用DFS
  dfs(1, 0, 0);
  // 取答案
  for (int i = 1; i <= n; i++)
    printf("%d%c", col[bel[i]], " \n"[i == n]);
  return 0;
}