//
// Created by Emme.Kwok on 2026/9/29.
//
#include<bits/stdc++.h>
using namespace std;

int a[105], seat[15][15];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    int r = a[1], pos = 1;
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int j = 1; j <= m; j++) {
        if (j % 2) {
            for (int i = 1; i <= n; i++, pos++) seat[i][j] = a[pos];
        } else {
            for (int i = n; i >= 1; i--, pos++) seat[i][j] = a[pos];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (seat[i][j] == r) cout << j << " " << i << endl, exit(0);
    return 0;
}