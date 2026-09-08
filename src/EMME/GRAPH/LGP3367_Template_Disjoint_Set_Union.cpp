//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

int fa[200005];

int find(int x) {
    while (fa[x] != x)
        fa[x] = fa[fa[x]], x = fa[x];
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, y, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> z >> x >> y;
        if (z == 1) {
            int fu = find(x), fv = find(y);
            if (fu != fv) fa[fu] = fv;
        } else {
            if (find(x) == find(y)) cout << "Y\n";
            else cout << "N\n";
        }
    }
    return 0;
}