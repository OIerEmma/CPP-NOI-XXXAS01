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
            a[0][j] += a[i][j];
        }
    }
    int idx = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < a[0][i]) {
            ans = a[0][i];
            idx = i;
        }
    }
    cout << idx << " " << ans << endl;
    return 0;
}