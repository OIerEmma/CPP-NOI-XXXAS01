//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, vis[41][41];
char mp[41][41];
struct node {int x, y; node* parent; };

void print(node* n) {
    if (n == nullptr) return;
    print(n->parent);
    cout << "(" << n->x - 1 << ", " << n->y - 1 << ")" << endl;
}

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y, nullptr});
    vis[x][y] = 1;
    while (!q.empty()) {
        node* now = &q.front(); q.pop();
        if (now->x == r && now->y == c) {
            print(now);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int xx = now->x + dx[i], yy = now->y + dy[i];
            if (xx < 1 || xx > r || yy < 1 || yy > c || mp[xx][yy] == '1' || vis[xx][yy]) continue;
            q.push({xx, yy, now});
            vis[xx][yy] = vis[now->x][now->y] + 1;
        }
    }
}

int main() {
    // cin >> r >> c;
    r = 5, c = 5;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> mp[i][j];
        }
    }
    bfs(1, 1);
    return 0;
}