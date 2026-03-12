//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

int main() {
    freopen("mod.in", "r", stdin);
    freopen("mod.out", "w", stdout);
    int p, q, l, r;
    cin >> p >> q;
    long long ans = 0;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            ans += p % j;
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}