//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int fa[20005];

int find(int x) {
    while (fa[x] != x)
        fa[x] = fa[fa[x]], x = fa[x];
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int fu = find(u), fv = find(v);
        if (fu != fv) fa[fu] = fv;
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        if (find(x) == find(y)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}