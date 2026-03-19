//
// Created by Geek.Kwok on 2026/3/19.
//
#include <bits/stdc++.h>
using namespace std;

#define N 101
char c[N][N];
int n, m, cnt, vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node {int x, y;};

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y}); // 首节点入队
    vis[x][y] = cnt; // 标记
    while (!q.empty()) {
        node head = q.front(); // 获取队头
        q.pop(); // 队头出队
        for (int i = 0; i < 4; i++) {
            int xx = head.x + dx[i], yy = head.y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || c[xx][yy] == '0') continue;
            vis[xx][yy] = cnt; // 标记
            q.push({xx, yy});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && c[i][j] != '0') {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}