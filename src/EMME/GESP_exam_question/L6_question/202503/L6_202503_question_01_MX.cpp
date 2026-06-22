//
// Created by Emme.Kwok on 2026/6/22.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int c[N], cnt[2];

// DFS : 先序+参数
void dfs(int root, int colour, int parent) {
    c[root] = colour;
    cnt[colour]++;
    for (int ch : g[root]) if (ch != parent) dfs(ch, !colour, root);
}

int main() {
    int n;
    cin >> n;
    // 建树
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // 调用DFS
    dfs(1, 0, 0);
    // 取答案
    for (int i = 1; i <= n; i++) printf("%d%c", cnt[c[i]], " \n"[i == n]);
    return 0;
}