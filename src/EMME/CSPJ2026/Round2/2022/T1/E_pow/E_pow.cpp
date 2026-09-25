//
// Created by Emme.Kwok on 2026/9/23.
//
#include<bits/stdc++.h>
using namespace std;

const int p = 1e9;

int main() {
    // freopen("E_pow.in", "r", stdin);
    // freopen("E_pow.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a == 1) cout << "1\n", exit(0);
    long long ans = a;
    for (int i = 2; i <= b; i++) {
        if (ans * a <= p) ans *= a;
        else cout << "-1\n", exit(0);
    }
    cout << ans << endl;
    return 0;
}