//
// Created by Emme.Kwok on 2026/8/30.
//
#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];
bool color[100005];
int ans;

// 定义：遍历所有节点 且白色节点下的子节点含有黑色节点
bool dfs(int start, int fa) {
    // if (color[start]) return true;
    bool flag = false;
    for (int v : g[start]) if (v != fa) flag |= dfs(v, start);
    flag |= color[start];
    if (!color[start] && flag) ans++; // 自己是白色且子节点黑色
    // cout << start << " " << flag << endl;
    return flag;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> color[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
/*
7
1 0 0 1 0 1 0
1 2
1 3
2 4
3 5
3 6
6 7
*/