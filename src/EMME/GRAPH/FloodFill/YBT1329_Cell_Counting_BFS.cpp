//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1005, M = 1005, K = 4;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int n, m, ans;
bool vis[N][M];
char grid[N][M];
struct node {
    int x, y;
};

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        node u = q.front(); q.pop();
        for (int i = 0; i < K; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && grid[nx][ny] != '0') {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] && grid[i][j] != '0') {
                bfs(i, j);
                ans++;
            }
    cout << ans << endl;
    return 0;
}