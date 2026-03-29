//
// Created by Emme.Kwok on 2026/3/28.
//
#include<iostream>
#include<queue>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int m, n, mp[55][55], cnt, ans = -1, res;
bool vis[55][55];
struct node {
    int x, y;
};

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = true;
    res = 1;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[u.x][u.y] >> i & 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = true;
            res++;
        }
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