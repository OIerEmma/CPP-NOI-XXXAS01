//
// Created by Geek.Kwok on 2026/3/22.
//
#include <bits/stdc++.h>
using namespace std;

int A, B, Q, xx0, yy0, f[2005][2005];

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];
    if (x == 0) return f[x][y] = y;
    return f[x][y] = dfs(x + x * y / A - (x + B - 1)/B, y - x * y / A);
}

int main() {
    cin >> A >> B >> Q;
    while (Q--) {
        cin >> xx0 >> yy0;
        cout << dfs(xx0, yy0) << endl;
    }
    return 0;
}