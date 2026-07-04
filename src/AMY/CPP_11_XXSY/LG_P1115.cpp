//
// Created by Emme.Kwok on 2026/7/4.
//
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = -1e18;
    ll min_s = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pre[i] - min_s);
        min_s = min(min_s, pre[i]);
    }
    cout << ans << endl;
    return 0;
}