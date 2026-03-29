//
// Created by Emme.Kwok on 2026/3/28.
//
#include<iostream>
#include<queue>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int r, c, vis[45][45];
char mp[45][45];
struct node {
    int x, y;
};

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        if (u.x == r && u.y == c) return vis[r][c];
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if (nx < 1 || nx > r || ny < 1 || ny > c || mp[nx][ny] == '#' || vis[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = vis[u.x][u.y] + 1;
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