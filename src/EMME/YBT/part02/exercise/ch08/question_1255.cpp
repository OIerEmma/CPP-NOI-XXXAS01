//
// Created by Emme.Kwok on 2026/3/29.
//
#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int mp[10][10], ans;
bool vis[10][10];
struct node {
    int x, y;
    node *pn;
};

void print(node* u) {
    if (u == nullptr) return;
    print(u->pn);
    cout << "(" << u->x << ", " << u->y << ")" << endl;
}

void bfs(int x, int y) {
    queue<node> q;
    q.push({x, y, nullptr});
    vis[x][y] = true;
    while (!q.empty()) {
        node* u = &q.front();
        // node uu = p1;
        // node uu = q.front();
        // node* pn = &uu;
        q.pop();
        if (u->x == 4 && u->y == 4) {
            print(u);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = u->x + dx[i], ny = u->y + dy[i];
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || vis[nx][ny] || mp[nx][ny] == 1) continue;
            q.push({nx, ny, u});
            vis[nx][ny] = true;
        }
    }
}

int main() {
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            cin >> mp[i][j];
        }
    }
    bfs(0, 0);
    return 0;
}