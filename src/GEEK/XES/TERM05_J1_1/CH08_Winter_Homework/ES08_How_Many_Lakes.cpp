//
// Created by Geek.Kwok on 2026/3/20.
//
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int n, m, cnt, g[100010], vis[105][105];
char mp[105][105];

void dfs(int x, int y) {
    vis[x][y] = cnt;
    g[cnt]++;
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || mp[xx][yy] == '.') continue;
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
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && mp[i][j] == 'W') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    sort(g + 1, g + cnt + 1);
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << g[i] << " ";
    }
    return 0;
}