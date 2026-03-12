//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 105;
int a[maxn][maxn];

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][0] += a[i][j];
        }
    }
    int idx = 0, ans = 0;
    for (int i = 1; i <= m; i++) {
        if (ans < a[i][0]) {
            ans = a[i][0];
            idx = i;
        }
    }
    cout << idx << " " << ans << endl;
    return 0;
}