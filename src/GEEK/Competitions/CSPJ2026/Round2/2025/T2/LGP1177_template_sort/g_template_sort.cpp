//
// Created by Geek.Kwok on 2026/9/29.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("g_template_sort.in", "r", stdin);
    // freopen("g_template_sort.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}