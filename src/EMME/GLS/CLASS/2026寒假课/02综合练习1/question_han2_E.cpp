//
// Created by Emme.Kwok on 2026/2/1.
//
#include<iostream>
using namespace std;

const int maxn = 1500000;

struct node {
    long long w, u;
    double x;
}cow[maxn];

bool cmp(node x, node y) {
    if (x.u == y.u) {
        return x.w < y.w;
    }
    return x.u > y.u;
}

int main() {
    int n, m;
    int a, b, c, d;
    int e, f, g, h;
    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
    for (int i = 0; i < 3 * n; i++) {
        cow[i].w = (a * (long long)pow(i, 5) + b * (long long)pow(i, 3) + c) % d;
        cow[i].u = (e * (long long)pow(i, 5) + f * (long long)pow(i, 3) + g) % h;
        cow[i].x = (double)cow[i].w / (double)cow[i].u;
    }
    sort(cow + 1, cow + 3 * n + 1, cmp);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cow[i].w;
    }
    cout << ans % m << endl;
    return 0;
}