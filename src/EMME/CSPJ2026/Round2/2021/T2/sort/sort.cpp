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
    int n, q, type, x, v;
    bool flag = false;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].v, sa[i].v = a[i].v, a[i].s = sa[i].s = i;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> v;
            node old = a[x];
            a[x].v = v;
            if (!flag) {
                sort(sa + 1, sa + n + 1, cmp);
                flag = true;
            } else {
                int pos = 0;
                for (int i = 1; i <= n; i++)
                    if (sa[i].v == old.v && sa[i].s == old.s) {
                        pos = i;
                        break;
                    }
                int next = 0;
                for (int i = 1; i <= n; i++)
                    if (sa[i].v >= sa[pos].v && i != pos) { next = i; break; }
                if (pos < next) {
                    for (int i = pos + 1; i < next; i++)
                        swap(sa[i], sa[i - 1]);
                } else if (pos > next) {
                    for (int i = pos + 1; i >= next; i--)
                        swap(sa[i], sa[i - 1]);
                }
            }
        } else {
            cin >> x;
            for (int i = 1; i <= n; i++)
                if (sa[i].v == a[x].v && sa[i].s == a[x].s) { cout << i << endl; break; }
        }
    }
    return 0;
}