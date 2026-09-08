//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    unordered_map<int, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) { int x; cin >> x, mp[x]++; }
    for (auto it : mp)
        if (mp.count(it.first + c)) ans += 1LL * it.second * mp[it.first + c];
    cout << ans << endl;
    return 0;
}