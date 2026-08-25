//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

char a[105][105];
bool vis[105][105];
int n, m;
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
        node now = q.front();
        q.pop();
        if (now.x == n && now.y == m) return true;
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] != '#') {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    if (bfs(1, 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}