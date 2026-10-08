//
// Created by Geek.Kwok on 2026/9/24.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_number3.in", "r", stdin);
    // freopen("g_number3.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n = 0;
    string s; cin >> s;
    for (auto ch: s) if (ch == '1') n++;
    cout << n << endl;
    return 0;
}