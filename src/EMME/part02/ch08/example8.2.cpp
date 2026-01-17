//
// Created by Emme.Kwok on 2025/12/14.
//
#include<iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int a[100][100];
int n, m, ans;

void bfs(int p, int q) {
    int t = 0, w = 1;
    int h[1000][3];
    ans++;
    a[p][q] = 0;
    h[1][1] = p;
    h[1][2] = q;
    int x, y;
    do {
        t++;
        for (int i = 0; i <= 3; i++) {
            x = h[t][1] + dx[i];
            y = h[t][2] + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && a[x][y]) {
                w++;
                h[w][1] = x;
                h[w][2] = y;
                a[x][y] = 0;
            }
        }
    } while (t < w);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }
    char s[10000];
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}