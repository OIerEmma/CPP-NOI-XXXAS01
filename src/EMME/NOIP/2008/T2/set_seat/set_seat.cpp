//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

pair<int, int> c[1005], r[1005];
struct node {
    int x, y, p, q;
} t[2005];

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.first == y.first) return x.second < y.second;
    return x.first > y.first;
}
bool cmp2(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}

int main() {
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    for (int i = 1, x, y, p, q; i <= d; i++) {
        cin >> x >> y >> p >> q;
        if (x == p) c[min(y, q)].first++, c[min(y, q)].second = min(y, q);
        else if (y == q) r[min(x, p)].first++, r[min(x, p)].second = min(x, p);
    }
    sort(r + 1, r + n, cmp);
    sort(r + 1, r + k + 1, cmp2);
    sort(c + 1, c + m, cmp);
    sort(c + 1, c + l + 1, cmp2);
    for (int i = 1; i < k; i++) cout << r[i].second << " ";
    cout << r[k].second << "\n";
    for (int i = 1; i < l; i++) cout << c[i].second << " ";
    cout << c[l].second << "\n";
    return 0;
}
/*
4 5 1 2 3
4 2 4 3
2 3 3 3
2 5 2 4
*/