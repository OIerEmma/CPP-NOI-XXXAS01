//
// Created by Emme.Kwok on 2026/9/27.
//
#include<bits/stdc++.h>
using namespace std;

// d=0代表向东，d=1代表向南，d=2代表向西，d=3代表向北
const int di[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k, x, y, d;
char mp[1005][1005];
bool vis[1005][1005];
struct node {
    int x, y;
};

void bfs(int dir, int x, int y) {
    int step = k;
    queue<node> q;
    q.push({x, y});
    vis[x][y] = true;
    while (step > 0) {
        node u = q.front();
        q.pop();
        int nx = u.x + di[dir][0], ny = u.y + di[dir][1];
        while (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == 'x' && step > 0) {
            dir = (dir + 1) % 4;
            nx = u.x + di[dir][0], ny = u.y + di[dir][1];
            step--;
        }
        vis[nx][ny] = true;
        q.push({nx, ny});
        step--;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) cin >> mp[i][j];
        memset(vis, false, sizeof vis);
        bfs(d, x, y);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) ans += vis[i][j];
        cout << ans << endl;
    }
    return 0;
}