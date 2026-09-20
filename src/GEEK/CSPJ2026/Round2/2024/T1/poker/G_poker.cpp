//
// Created by Geek.Kwok on 2026/9/20.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("G_poker.in", "r", stdin);
    // freopen("G_poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n;
    string s;
    set<string> own;
    cin >> n;
    while (n--) { cin >> s; own.insert(s); }
    cout << 52 - own.size() << endl;
    return 0;
}