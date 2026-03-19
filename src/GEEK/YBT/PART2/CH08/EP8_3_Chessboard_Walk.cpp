//
// Created by Geek.Kwok on 2026/3/19.
//
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -2, -2};
int dy[] = {-2, -1, -2};
int ax, ay, bx, by, vis[101][101];
struct node {int x, y;};

int bfs(int x, int y) {
    queue<node> q;
    q.push({x, y});
    vis[x][y] = 0;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) {
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if (xx < 1 || yy < 1 || vis[xx][yy]) continue;
            vis[xx][yy] = vis[x][y] + 1;
            if (xx == 1 && yy == 1) {
                return vis[xx][yy];
            }
            q.push({xx, yy});
        }
    }
}

int main() {
    cin >> ax >> ay >> bx >> by;
    cout << bfs(ax, ay) << endl;
    memset(vis, 0, sizeof vis);
    cout << bfs(bx, by) << endl;
    return 0;
}