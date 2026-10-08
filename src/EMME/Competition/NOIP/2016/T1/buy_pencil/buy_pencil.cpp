//
// Created by Geek.Kwok on 2026/10/4.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long W, ans = 1e18, w, v;
    cin >> W;
    for (int i = 1; i <= 3; i++) {
        cin >> w >> v;
        ans = min(ans, (long long)ceil(W * 1.0 / w) * v);
    }
    cout << ans << endl;
    return 0;
}