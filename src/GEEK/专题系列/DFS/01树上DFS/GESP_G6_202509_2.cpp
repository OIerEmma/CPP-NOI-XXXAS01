//
// Created by Geek.Kwok on 6/22/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<pair<int, int>> G[N];
long long mx;

// DFS: 先序 + 参数
void dfs(int root, int parent, long long dist) {
    mx = max(mx, dist);
    for (auto p : G[root])
        if (p.first != parent)
            dfs(p.first, root, dist + p.second);
}

int main() {
    int n;
    long long sum = 0;
    cin >> n;
    // 建树：邻接表存树（当未告知节点父子关系时）
    for (int u, v, w, i = 1; i < n; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        sum += w;
    }
    // 调用DFS
    dfs(1, 0, 0);
    // 取答案
    cout << 2 * sum - mx << endl;
    return 0;
}