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
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, q, type, x, v;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].v, sa[i].v = a[i].v, a[i].s = sa[i].s = i;
    sort(sa + 1, sa + n + 1, cmp);
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> v;
            node old = a[x];
            a[x].v = v;
            int pos = 0;
            for (int i = 1; i <= n; i++)
                if (sa[i].v == old.v && sa[i].s == old.s) {
                    pos = i;
                    break;
                }
            sa[pos].v = v;
            for (int i = pos; i > 1; i--) {
                if (sa[i - 1].v > sa[i].v || sa[i - 1].v == sa[i].v && sa[i - 1].s > sa[i].s)
                    swap(sa[i], sa[i - 1]);
                else break;
            }
            for (int i = pos; i < n; i++) {
                if (sa[i].v > sa[i + 1].v || sa[i].v == sa[i + 1].v && sa[i].s > sa[i + 1].s)
                    swap(sa[i], sa[i + 1]);
                else break;
            }
        } else {
            cin >> x;
            // for (int i = 1; i <= n; i++) cout << a[i].v << " " << a[i].s << endl;
            // cout << endl;
            // for (int i = 1; i <= n; i++) cout << sa[i].v << " " << sa[i].s << endl;
            // cout << endl;
            for (int i = 1; i <= n; i++)
                if (sa[i].v == a[x].v && sa[i].s == a[x].s) { cout << i << "\n"; break; }
        }
    }
    return 0;
}