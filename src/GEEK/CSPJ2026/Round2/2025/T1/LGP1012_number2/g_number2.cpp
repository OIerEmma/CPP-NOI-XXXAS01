//
// Created by Geek.Kwok on 2026/9/22.
//
#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    // freopen("g_number2.in", "r", stdin);
    // freopen("g_number2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n; string os;
    vector<string> sarr;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> os, sarr.push_back(os);
    sort(sarr.begin(), sarr.end(), cmp);
    for (const auto& s: sarr) cout << s;
    cout << endl;
    return 0;
}