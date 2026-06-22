//
// Created by Emme.Kwok on 2026/6/22.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> g[N];
long long ans;

// DFS : 先序 + 参数
void dfs(int root, long long sum, int parent) {
    ans = max(ans, sum);
    for (auto ch : g[root])
        if (ch.first != parent)
            dfs(ch.first, sum + ch.second, root);
}

int main() {
    int n;
    cin >> n;
    // 建树：邻接表存树
    long long s = 0;
    for (int i = 1; i < n; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].push_back({v, l});
        g[v].push_back({u, l});
        s += l;
    }
    // 调用DFS
    dfs(1, 0, 0);
    // 取答案
    cout << 2 * s - ans << endl;
    return 0;
}