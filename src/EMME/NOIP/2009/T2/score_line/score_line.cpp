//
// Created by Geek.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int k, s;
} a[5005];

bool cmp(node x, node y) {
    if (x.s == y.s) return x.k < y.k;
    return x.s > y.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].k >> a[i].s;
    sort(a + 1, a + n + 1, cmp);
    int x = int(m * 1.5), ls = a[x].s;
    for (int i = x + 1; i <= n; i++)
        if (a[i].s == ls) x++;
    cout << ls << " " << x << "\n";
    for (int i = 1; i <= x; i++) cout << a[i].k << " " << a[i].s << "\n";
    return 0;
}