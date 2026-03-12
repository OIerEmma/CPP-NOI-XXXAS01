//
// Created by Emme.Kwok on 2026/2/2.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 105;
struct node {
    int n, v;
    double onev;
} m[maxn];

bool cmp(node x, node y) {
    return x.onev > y.onev;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        int w, s;
        cin >> w >> s;
        for (int i = 1; i <= s; i++) {
            cin >> m[i].n >> m[i].v;
            m[i].onev = (double)m[i].v / m[i].n;
        }
        sort(m + 1, m + s + 1, cmp);
        int i = 1, nown = 0;
        double ans = 0;
        while (i <= s && nown + m[i].n < w) {
            nown += m[i].n;
            ans += m[i].v;
            i++;
        }
        ans += (w - nown) * m[i].onev;
        printf("%.2lf\n", ans);
    }
    return 0;
}
/*
36662.37
31454.21
23303.20
3329.00
20173.30
32511.71
63859.73
76612.07
21324.37
5360.27
 */