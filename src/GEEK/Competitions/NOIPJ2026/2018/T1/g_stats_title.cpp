//
// Created by Geek.Kwok on 2026/10/11.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("g_stats_title.in", "r", stdin);
    // freopen("g_stats_title.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    char s[10];
    memset(s, 0, sizeof s);
    cin.getline(s, 10);
    int cnt = 0;
    for (char c : s) if (c != ' ' && c != '\n' && c != 0) cnt++;
    cout << cnt << endl;
    return 0;
}