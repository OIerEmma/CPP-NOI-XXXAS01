//
// Created by Amy on 2026/7/10.
//
#include<bits/stdc++.h>
using namespace std;
int n, x, y, cnt, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        if (x >= 90 && x <= 140 && y >= 60 && y <= 90) {
            cnt++;
        }else {
            if (cnt > ans) ans = cnt;
            cnt = 0;
        }
    }
    if (cnt > ans) ans = cnt;
    cout << ans;
    return 0;
}