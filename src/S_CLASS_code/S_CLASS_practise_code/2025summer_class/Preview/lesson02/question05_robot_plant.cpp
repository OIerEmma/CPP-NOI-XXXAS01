//
// Created by Emma on 2025/7/11.
//
#include<iostream>
using namespace std;

bool a[310][310];
int x[310], x2[310], y[310], y2[310];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = false;
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i] >> x2[i] >> y2[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = y[i]; j <= y2[i]; j++) {
            for (int s = x[i]; s <= x2[i]; s++) {
                a[s][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
6 4 2
1 1 2 4
1 3 5 4
*/
