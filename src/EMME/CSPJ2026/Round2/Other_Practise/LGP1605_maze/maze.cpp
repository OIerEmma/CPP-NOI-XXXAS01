//
// Created by Emme.Kwok on 2026/9/26.
//
#include<bits/stdc++.h>
using namespace std;

int n, m, t, sx, sy, fx, fy;
int mp[20][20], ans;
bool vis[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] || vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(nx,ny);
        vis[nx][ny] = false;
    }
}
int main() {
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for(int i = 1, x, y; i <= t; i++) {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    vis[sx][sy] = true;
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}
