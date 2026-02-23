//
// Created by Emme.Kwok on 2026/2/3.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    string s, t;
    cin >> s >> t;
    int ans = 0;
    while (s != t) {
        ans++;
        char c = s[0];
        s = s.substr(0, s.size() - 1);
        s = c + s;
    }
    cout << ans << endl;
    return 0;
}