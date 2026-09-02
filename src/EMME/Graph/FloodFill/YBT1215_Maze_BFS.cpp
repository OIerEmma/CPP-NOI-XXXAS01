//
// Created by Emme.Kwok on 2026/9/2.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int n, x, y, z, r;
bool vis[MAXN][MAXN];
char a[MAXN][MAXN];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
            if (nx == z + 1 && ny == r + 1) return true;
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny] && a[nx][ny] == '.') {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) cin >> a[i][j];
        memset(vis, false, sizeof vis);
        cin >> x >> y >> z >> r;
        cout << (bfs(x + 1, y + 1) ? "YES" : "NO") << "\n";
    }
    return 0;
}