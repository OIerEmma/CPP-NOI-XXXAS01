//
// Created by Emme.Kwok on 2026/8/30.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN], col(MAXN), dep(MAXN), has(MAXN);

void dfs(int start, int fa) {
    dep[start] = dep[fa] + 1;
    for (int v : g[start])
        if (v != fa) dfs(v, start);
}

bool dfs2(int start, int fa) {
    for (int v : g[start])
        if (v != fa) {
            if (!dfs2(v, start)) return false;
            if (col[v] || has[v]) has[start]++;
        }
    return has[start] <= 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            has[i] = dep[i] = 0, g[i].clear();
        for (int i = 1; i <= n; i++) cin >> col[i];
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
        int maxd = -1, pos = 0;
        for (int i = 1; i <= n; i++)
            if (maxd < dep[i] && col[i])
                maxd = dep[i], pos = i;
        cout << (dfs2(pos, 0) ? "Yes" : "No") << endl;
    }
    return 0;
}