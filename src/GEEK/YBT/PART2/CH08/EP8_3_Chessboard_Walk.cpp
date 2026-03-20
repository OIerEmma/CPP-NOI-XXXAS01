//
// Created by Geek.Kwok on 2026/3/19.
//
#include <bits/stdc++.h>
using namespace std;

#define N 101
int dx[] = {-1, -2, -1, -2, 1, 2, 1, 2, -2, 2, 2, -2};
int dy[] = {-2, -1, 2, 1, 2, 1, -2, -1, -2, 2, -2, 2};
int ax, ay, bx, by, vis[N + 1][N + 1];
struct node {int x, y;};

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 0;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 12; i++) {
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if (xx < 1 || xx > N || yy < 1 || yy > N || vis[xx][yy]) continue;
            vis[xx][yy] = vis[now.x][now.y] + 1;
            if (xx == 1 && yy == 1) {
                return vis[xx][yy];
            }
            q.push({xx, yy});
        }
    }
    return -1;
}

int main() {
    cin >> ax >> ay >> bx >> by;
    cout << bfs(ax, ay) << endl;
    memset(vis, 0, sizeof vis);
    cout << bfs(bx, by) << endl;
    return 0;
}