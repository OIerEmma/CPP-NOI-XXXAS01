//
// Created by Geek.Kwok on 2026/3/21.
//
#include<bits/stdc++.h>
using namespace std;

const int dx[] = {1, 1, -1, -1, 0, 0, 1, -1};
const int dy[] = {1, -1, 1, -1, 1, -1, 0, 0};
char mp[1005][1005];
int vis[1005][1005];
bool seecup[1005][1005];
struct node{
    int x, y;
};

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    int k, sx, sy, ex, ey;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> sx >> sy >> ex >> ey;
        if (sx == ex && sy == ey) { cout << 0 << endl; continue; }
        memset(vis, -1, sizeof vis);
        memset(seecup, false, sizeof seecup);
        for (int i = 4; i < 8; i++) {
            int x = ex, y = ey;
            while (x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == 'O') {
                seecup[x][y] = true;
                x += dx[i];
                y += dy[i];
            }
        }
        if (seecup[sx][sy]) { cout << 1 << endl; continue; }

        queue<node> q;
        int minv = 10e9;
        q.push({sx, sy});
        vis[sx][sy] = 0;
        bool flag = true;
        while (!q.empty()) {
            node u = q.front();
            q.pop();
            if (seecup[u.x][u.y]) {
                if (u.x == ex && u.y == ey) minv = min(minv, vis[u.x][u.y]);
                else minv = min(minv, vis[u.x][u.y] + 1);;
                flag = false;
            }
            for (int i = 0; i < 8; i++) {
                int nx = u.x + dx[i], ny = u.y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'X' || vis[nx][ny] != -1) continue;
                vis[nx][ny] = vis[u.x][u.y] + 1;
                q.push({nx, ny});
            }
        }
        if (flag) cout << -1 << endl;
        else cout << minv << endl;
    }
    return 0;
}