//
// Created by Amy on 2026/7/21.
//
#include<bits/stdc++.h>
using namespace std;

int n, x, maxx, minx;

int main() {
    cin >> n;
    cin >> maxx;
    minx = maxx;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        maxx = max(x, maxx);
            minx = min(x, minx);
    }
    cout << minx << ' ' << maxx;
    return 0;
}
