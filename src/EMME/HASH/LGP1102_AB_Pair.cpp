//
// Created by Emme.Kwok on 2026/9/8.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    map<int, int> mp;
    for (int i = 1, a; i <= n; i++) cin >> a, mp[a]++;
    long long ans = 0;
    for (auto p : mp)
        if (mp.count(p.first + c))
            ans += 1LL * mp[p.first] * mp[p.first + c];
    cout << ans << endl;
    return 0;
}