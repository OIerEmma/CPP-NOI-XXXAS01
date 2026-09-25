//
// Created by Emme.Kwok on 2026/9/24.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("candy.in", "r", stdin);
    // freopen("candy.out", "w", stdout);
    int n, l, r;
    cin >> n >> l >> r;
    // ----- 90分 -----
    // int f = 0, ans = 0;
    // for (int i = l; i <= r; i++) {
    //     if (f == i % n) break;
    //     ans = max(ans, i % n);
    //     if (i == l) f = i % n;
    // }
    // cout << ans << endl;

    // ----- 100分 -----
    int rm = r % n;
    int ld = l / n, rd = r / n;
    if (ld < rd) cout << n - 1 << endl;
    else cout << rm << endl;
    return 0;
}