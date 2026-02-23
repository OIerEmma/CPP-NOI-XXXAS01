//
// Created by Emme.Kwok on 2026/2/1.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int n, a;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ans += a - 1;
    }
    cout << ans << endl;
    return 0;
}