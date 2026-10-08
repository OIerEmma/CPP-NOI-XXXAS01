//
// Created by Geek.Kwok on 2026/10/6.
//
#include<bits/stdc++.h>
using namespace std;

map<int, int> amp, nmp;

map<int, int> fj(int x) {
    map<int, int> mp;
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) x /= i, mp[i]++;
    if (x > 1) mp[x]++;
    return mp;
}

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    nmp = fj(m1);
    int ans = -1;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        amp = fj(a);
        bool flag = true;
        int ares = 0;
        for (auto p : nmp) {
            if (amp.count(p.first)) ares = max(ares, (p.second * m2 + amp[p.first] - 1) / amp[p.first]);
            else { flag = false; break; }
        }
        if (flag) ans = (ans == -1 ? ares : min(ans, ares));
    }
    cout << ans << endl;
    return 0;
}