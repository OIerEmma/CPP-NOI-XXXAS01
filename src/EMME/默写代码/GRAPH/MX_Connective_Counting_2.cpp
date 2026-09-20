//
// Created by Geek.Kwok on 2026/9/12.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int fa[N];

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
        int fv = find(u), fu = find(v);
        if (fv != fu) fa[fu] = fv;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (fa[i] == i) ans++;
    cout << ans - 1 << endl;
    return 0;
}