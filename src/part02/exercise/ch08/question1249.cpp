//
// Created by Emme.Kwok on 2025/12/16.
//
#include<iostream>
using namespace std;

const int dx[] = {0, 0, -1, 1, 1, -1, 1, -1},
          dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
struct node {
    int x, y;
};
char a[111][111];
bool vis[111][111];
int n, m, ans;

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = true;
    ans++;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int d = 0; d < 8; d++) {
            int nx = now.x + dx[d], ny = now.y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 'W' && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
        getchar();
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'W' && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}