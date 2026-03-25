//
// Created by Geek.Kwok on 2026/3/25.
//
#include <bits/stdc++.h>
using namespace std;

#define N 51
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int mp[N][N], m, n, vis[N][N];
int cnt, ans, g[N * N];

void dfs(int x, int y) {
    vis[x][y] = cnt;
    g[cnt]++;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > m || yy < 1 || yy > n || vis[xx][yy] || (mp[x][y] >> i) & 1) continue;
        dfs(xx, yy);
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j =  1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j =  1; j <= n; j++) {
            if (!vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        ans = max(ans, g[i]);
    }
    cout << cnt << endl << ans << endl;
    return 0;
}