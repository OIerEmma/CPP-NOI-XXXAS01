//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

const int MOD = 20123;
bool a[10005][105];
int haveS[10005], x[10005][105];

int main() {
    int n, m, d;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j] >> x[i][j];
            haveS[i] += a[i][j];
        }
    cin >> d;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << d << endl;
        ans = (ans + x[i][d]) % MOD;
        x[i][d] %= haveS[i];
        if (x[i][d] == 0) x[i][d] = haveS[i];
        int cnt = 0;
        for (int j = d; j < d + m; j++) {
            if (a[i][j % m]) cnt++;
            if (cnt == x[i][d]) { d = j % m; break; }
        }
    }
    cout << ans << endl;
    return 0;
}