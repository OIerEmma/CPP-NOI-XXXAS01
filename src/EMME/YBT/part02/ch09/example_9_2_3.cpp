//
// Created by Emme.Kwok on 2026/4/26.
//
#include<iostream>
using namespace std;

int n;
int a[1005][1005], f[1005][1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) cin >> a[i][j];
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = a[i][j] + max(f[i - 1][j - 1], f[i - 1][j]);
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) ans = max(f[n][i], ans);
    cout << ans << endl;
    return 0;
}