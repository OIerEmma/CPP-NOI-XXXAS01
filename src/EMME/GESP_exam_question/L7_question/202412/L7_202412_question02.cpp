//
// Created by Emme.Kwok on 2026/8/30.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> g[MAXN], a(MAXN), down(MAXN), up(MAXN);

void dfsDown(int start, int fa) {
    for (int v : g[start])
        if (fa != v) {
            dfsDown(v, start);
            if (a[v] < a[start]) down[start] += down[v];
        }
    down[start]++;
}

void dfsUp(int start, int fa) {
    if (a[start] > a[fa]) up[start] += up[fa] + down[fa];
    for (int v : g[start])
        if (fa != v) dfsUp(v, start);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfsDown(1, 0);
    dfsUp(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, down[i] + up[i]);
    cout << ans << endl;
    return 0;
}