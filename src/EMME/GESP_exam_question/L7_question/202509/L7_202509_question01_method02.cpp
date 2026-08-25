//
// Created by Emme.Kwok on 2026/8/25.
//
#include<bits/stdc++.h>
using namespace std;

int fa[100005];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int fu = find(u), fv = find(v);
        if (fu != fv) fa[fu] = fv;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) == i) ans++;
    cout << ans - 1 << endl;
    return 0;
}