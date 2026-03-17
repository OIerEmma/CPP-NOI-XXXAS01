//
// Created by Geek.Kwok on 2026/3/17.
//
#include <bits/stdc++.h>
using namespace std;

#define N 101

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, ha, la, hb, lb;
char m[N][N];
bool f, vis[N][N];

void dfs(int x, int y) {
    if (x == hb && y == lb && !f) {
        f = true;
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= n || m[xx][yy] == '#' || vis[xx][yy]) continue;
        vis[xx][yy] = true;
        dfs(xx, yy);
    }
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        cin >> ha >> la >> hb >> lb;
        if (m[ha][la] == '#' || m[hb][lb] == '#') {
            cout << "NO" << endl;
            continue;
        }
        memset(vis, false, sizeof vis);
        vis[ha][la] = true;
        f = false;
        dfs(ha, la);
        if (!f) {
            cout << "NO" << endl;
        }
    }
    return 0;
}