//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 105, K = 8;
const int dx[K] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[K] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n, m, ans;
bool vis[N][N];
char a[N][N];
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
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == 'W') {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'W' && !vis[i][j])
                ans++, bfs(i, j);
    cout << ans << endl;
    return 0;
}