//
// Created by Emme.Kwok on 2026/3/28.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (m >= x) {
            m -= x;
        } else {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}