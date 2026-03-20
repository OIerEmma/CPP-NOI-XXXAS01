//
// Created by Geek.Kwok on 3/20/26.
#include <bits/stdc++.h>
using namespace std;

#define N 501

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, cnt, vis[N][N];
char mp[N][N];

void dfs(int x, int y) {
    vis[x][y] = cnt;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || mp[xx][yy] == '*' || vis[xx][yy]) continue;
        dfs(xx, yy);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i][1] && mp[i][1] == '0') {
            cnt++;
            dfs(i, 1);
        }
        if (!vis[i][m] && mp[i][m] == '0') {
            cnt++;
            dfs(i, m);
        }
        if (!vis[1][i] && mp[1][i] == '0') {
            cnt++;
            dfs(1, i);
        }
        if (!vis[m][i] && mp[m][i] == '0') {
            cnt++;
            dfs(m, i);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '0' && !vis[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}