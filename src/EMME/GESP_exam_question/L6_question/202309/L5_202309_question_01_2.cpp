//
// Created by Emme.Kwok on 2026/4/24.
//
#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int c, l;
    double s;
} d[505];

bool cmp(node x, node y) {
    if (x.c != y.c) {
        return x.c < y.c;
    }
    return x.s > y.s;
}

int main() {
    int n, L;
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].c >> d[i].l;
        d[i].s = d[i].l * 1.0 / d[i].c;
    }
    sort(d + 1, d + n + 1, cmp);
    int now = 0, ans = 0, i = 1;
    while (now < L && i <= n) {
        now += d[i].l;
        ans += d[i].c;
        cout << now << " " << ans << " " << d[i].l << " " << d[i].c << endl;
        i++;
    }
    if (now < L) cout << "no solution" << endl;
    else cout << ans << endl;
    return 0;
}