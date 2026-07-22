//
// Created by Amy on 2026/7/1.
//
#include<bits/stdc++.h>
using namespace std;
int n, j, y, t, x, p, z;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> p >> z;
        j += x;
        y += p;
        t += z;
    }
    cout << j << " " << y << " " << t << " " << j + y + t;
    return 0;
}
