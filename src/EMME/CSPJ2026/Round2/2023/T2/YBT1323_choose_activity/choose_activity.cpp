//
// Created by Emme.Kwok on 2026/9/28.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int b, e;
} a[1000005];

bool cmp(node x, node y) {
    return x.e < y.e;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].b >> a[i].e;
    sort(a + 1, a + n + 1, cmp);
    int last = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].b >= last) {
            ans++;
            last = a[i].e;
        }
    }
    cout << ans << endl;
    return 0;
}