//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, vis[41][41];
char mp[41][41];
struct node {int x, y; };

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        node now = q.front(); q.pop();
        if (now.x == r && now.y == c) {
            return vis[r][c];
        }
        for (int i = 0; i < 4; i++) {
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if (xx < 1 || xx > r || yy < 1 || yy > c || mp[xx][yy] == '#' || vis[xx][yy]) continue;
            q.push({xx, yy});
            vis[xx][yy] = vis[now.x][now.y] + 1;
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mp[i][j];
        }
    }
    cout << bfs(1, 1) << endl;
    return 0;
}