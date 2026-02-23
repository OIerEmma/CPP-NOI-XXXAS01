//
// Created by Emme.Kwok on 2026/1/31.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;

struct node {
    int t, idx;
}a[maxn];

bool cmp(node a, node b) {
    return a.t < b.t || a.t == b.t && a.idx < b.idx;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1, cmp);
    long long minn = 0;
    for (int i = 1; i <= n; i++) {
        minn += a[i].t * (n - i);
    }
    for (int i = 1; i < n; i++) {
        cout << a[i].idx << " ";
    }
    cout << a[n].idx;
    printf("\n%.2lf\n", (double)minn * 1.0 / n);
    return 0;
}
/*
20
56 12 1 99 1000 234 33 55 99 812 56 12 1 99 1000 234 33 55 99 812

3 13 2 12 7 17 8 18 1 11 4 9 14 19 6 16 10 20 5 15
703.85
 */