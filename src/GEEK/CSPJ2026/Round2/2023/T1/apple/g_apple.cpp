//
// Created by Geek.Kwok on 2026/9/21.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_apple.in", "r", stdin);
    // freopen("g_apple.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n;
    cin >> n;
    int days = 0, dayN = 0, r = n;
    while (r > 0) {
        days++;
        if (dayN == 0 && r % 3 == 1) dayN = days;
        r -= (r + 2) / 3;
    }
    cout << days << " " << dayN << endl;
    return 0;
}