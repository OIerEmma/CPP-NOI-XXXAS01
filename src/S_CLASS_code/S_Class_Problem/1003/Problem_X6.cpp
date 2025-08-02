//
// Created by Emma on 2025/7/2.
//
#include<iostream>
using namespace std;

int a[110][110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                ans += a[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}