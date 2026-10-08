//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int v, s;
} a[8005], sa[8005];

bool cmp(node x, node y) {
    if (x.v == y.v) return x.s < y.s;
    return x.v < y.v;
}

int main() {
    int n, q, type, x, v, flag = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].v, a[i].s = i;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> v;
            for (int i = 1; i <= n; i++)
                if (a[i].s == x) a[i].v = v;
        } else {
            sort(a + 1, a + n + 1, cmp);
            cin >> x;
            for (int i = 1; i <= n; i++)
                if (x == a[i].s) { cout << i << endl; break; }
        }
    }
    return 0;
}