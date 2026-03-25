//
// Created by Geek.Kwok on 2026/3/25.
//
#include <bits/stdc++.h>
using namespace std;

#define N 51
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int mp[N][N], m, n, vis[N][N];
int cnt, ans, res;

struct node {int x, y;};

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    res = 1;
    vis[x][y] = cnt;
    while (!q.empty()) {
        node now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if (xx < 1 || xx > m || yy < 1 || yy > n || vis[xx][yy] || (mp[now.x][now.y] >> i) & 1) continue;
            q.push({xx, yy});
            res++;
            vis[xx][yy] = cnt;
        }
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
                bfs(i, j);
                ans = max(ans, res);
            }
        }
    }
    cout << cnt << endl << ans << endl;
    return 0;
}