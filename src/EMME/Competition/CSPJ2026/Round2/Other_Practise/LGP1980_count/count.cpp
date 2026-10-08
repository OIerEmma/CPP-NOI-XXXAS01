//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    char c = char(x + '0');
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        for (char u : s) if (u == c) ans++;
    }
    cout << ans << endl;
    return 0;
}