//
// Created by Geek.Kwok on 2026/9/22.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("g_number.in", "r", stdin);
    freopen("g_number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    string s;
    cin >> s;
    vector<char> ch;
    for (auto c: s) if (c >= '0' && c <= '9') ch.push_back(c);
    sort(ch.begin(), ch.end(), greater<>());
    for (auto c: ch) cout << c;
    cout << endl;
    return 0;
}