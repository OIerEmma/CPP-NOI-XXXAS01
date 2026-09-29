//
// Created by Geek.Kwok on 2026/9/29.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_mm_random_numbers.in", "r", stdin);
    // freopen("g_mm_random_numbers.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n;
    set<int> s;
    cin >> n;
    for (int i = 0, a; i < n; i++) cin >> a, s.insert(a);
    cout << s.size() << endl;
    for (auto a: s) cout << a << " ";
    return 0;
}