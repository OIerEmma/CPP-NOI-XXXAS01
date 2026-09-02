//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 25;
int n, m, x, y;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
struct node {
    int x, y;
};

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = true;
    int area = 0;
    while (!q.empty()) {
        node u = q.front(); q.pop();
        area++;
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '.') {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return area;
}

int main() {
    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '@') x = i, y = j;
            }
        memset(vis, false, sizeof vis);
        cout << bfs(x, y) << endl;
    }
    return 0;
}