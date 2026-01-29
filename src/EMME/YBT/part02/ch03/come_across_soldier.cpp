//
// Created by Emme.Kwok on 2026/1/2.
//
#include<iostream>
using namespace std;

const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1},
          dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int n, m, x, y;
const int maxm = 25;
long long f[maxm][maxm];
bool g[maxm][maxm];

int main() {
    cin >> n >> m >> x >> y;
    g[x][y] = true;
    for (int i = 0; i < 8; i++) {
        if (x + dx[i] >= 0 && x + dx[i] <= n && y + dy[i] >= 0 && y + dy[i] <= m) {
            g[x + dx[i]][y + dy[i]] = true;
        }
    }
    f[0][0] = 1;
    for (int k = 1; k <= n; k++) {
        if (!g[k][0]) {
            f[k][0] = f[k - 1][0];
        }
    }
    for (int k = 1; k <= m; k++) {
        if (!g[0][k]) {
            f[0][k] = f[0][k - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!g[i][j]) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}