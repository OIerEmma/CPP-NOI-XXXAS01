//
// Created by Emme.Kwok on 2026/10/11.
//
#include<bits/stdc++.h>
using namespace std;

int b[4000005];

int main() {
    int n, m, maxn = 0;
    cin >> n >> m;
    set<int> s;
    vector<int> x;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        b[a]++;
        maxn = max(maxn, a);
        s.insert(a);
    }
    for (auto p : s) x.push_back(p);
    long long ans = 0, now = 0;
    for (int i = 1; i <= maxn; i++) {
        if (!b[i]) continue;
        while (i <= now) ans += min(b[i] * (now - i), ), i++;
        now += m;
    }
    cout << ans << endl;
    return 0;
}