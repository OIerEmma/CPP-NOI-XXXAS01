//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

int a[101][101], b[101][101];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int ans = 0;
            for (int x = 0; x < m; x++) {
                ans += a[i][x] * b[x][j];
            }
            if (j == k - 1) {
                cout << ans;
            } else {
                cout << ans << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

