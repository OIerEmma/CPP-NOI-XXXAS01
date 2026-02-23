//
// Created by Emme.Kwok on 2026/1/31.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;
int s[maxn];

struct node {
    int t, idx;
}a[maxn];

bool cmp(node a, node b) {
    return a.t < b.t || a.t == b.t && a.idx < b.idx;
}

int main() {
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1, cmp);
    double minn = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (cnt == r + 1) {
            cnt = 1;
        }
        s[cnt] += a[i].t;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i].idx << " ";
    }
    for (int i = 1; i <= n; i++) {
        minn += (double)s[i] * 1.0 / n;
    }
    printf("\n%.2lf\n", minn);
    return 0;
}