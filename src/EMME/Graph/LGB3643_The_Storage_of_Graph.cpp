//
// Created by Emme.Kwok on 2026/8/21.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> g[1005];
    vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        t[u][v] = t[v][u] = true;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << t[i][j] << " ";
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << g[i].size() << " ";
        sort(g[i].begin(), g[i].end());
        for (int j = 0; j < g[i].size(); j++) cout << g[i][j] << " ";
        cout << endl;
    }
    return 0;
}