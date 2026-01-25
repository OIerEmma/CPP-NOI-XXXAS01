//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;
struct node {
    int b, e;
} nd[maxn];

bool cmp(node x, node y) {
    return x.e < y.e;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nd[i].b >> nd[i].e;
    }
    sort(nd + 1, nd + n + 1, cmp);
    int ans = 0, laste = -1;
    for (int i = 1; i <= n; i++) {
        if (nd[i].b >= laste) {
            ans++;
            laste = nd[i].e;
        }
    }
    cout << ans << endl;
    return 0;
}