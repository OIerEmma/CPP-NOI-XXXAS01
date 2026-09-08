//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, m;
bool vis[MAXN][MAXN];
char a[MAXN][MAXN];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
struct node {
    int x, y;
};

bool bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        node u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx == n && ny == m) return true;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '.') {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    cout << (bfs(1, 1) ? "Yes" : "No");
    return 0;
}