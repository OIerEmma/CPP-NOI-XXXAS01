//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    for (int i = 1, a; i <= n; i++) cin >> a, ans ^= a;
    cout << ans << endl;
    return 0;
}