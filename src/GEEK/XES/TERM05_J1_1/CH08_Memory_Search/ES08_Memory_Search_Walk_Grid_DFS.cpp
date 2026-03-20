//
// Created by Geek.Kwok on 2026/3/19.
//
#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
int n, m, mp[1005][1005], cnt, mem[1005][1005];
bool vis[1005][1005];

void dfs(int x, int y) {
    if (mem[x][y]) return;
    if (x == n && y == m) {
        return;
    }
    for (int i = mp[x][y]; i >= 1; i--) {
        int nx = x + i, ny = y;
        if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[nx][ny] == 0) continue;
        if (mem[nx][ny]) { mem[x][y] += mem[nx][ny]; mem[x][y] %= mod; continue; }
        vis[nx][ny] = true;
        dfs(nx, ny);
        mem[x][y] += mem[nx][ny]; mem[x][y] %= mod;
        vis[nx][ny] = false;
    }
    for (int i = mp[x][y]; i >= 1; i--) {
        int nx = x, ny = y + i;
        if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[nx][ny] == 0) continue;
        if (mem[nx][ny]) { mem[x][y] += mem[nx][ny]; mem[x][y] %= mod; continue; }
        vis[nx][ny] = true;
        dfs(nx, ny);
        mem[x][y] += mem[nx][ny]; mem[x][y] %= mod;
        vis[nx][ny] = false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    mem[n][m] = 1;
    dfs(1, 1);
    cout <<  mem[1][1] << endl;
    return 0;
}