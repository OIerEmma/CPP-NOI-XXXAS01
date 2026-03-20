//
// Created by Geek.Kwok on 2026/3/19.
//
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, m;
int mp[1005][1005];
int mem[1005][1005];

void dfs(int x, int y) {
    if (mem[x][y]) return; // 已经计算过
    if (x == n && y == m) {
        mem[x][y] = 1;
        return;
    }

    int k = mp[x][y];
    long long sum = 0; // 用 long long 暂存，最后取模

    // 向下跳
    for (int i = 1; i <= k && x + i <= n; ++i) {
        int nx = x + i, ny = y;
        if (nx == n && ny == m) {
            sum += 1; // 直接到达终点
            continue;
        }
        if (mp[nx][ny] == 0) continue; // 跳到强度 0 的非终点格子无效
        if (!mem[nx][ny]) dfs(nx, ny);
        sum += mem[nx][ny];
    }

    // 向右跳
    for (int i = 1; i <= k && y + i <= m; ++i) {
        int nx = x, ny = y + i;
        if (nx == n && ny == m) {
            sum += 1;
            continue;
        }
        if (mp[nx][ny] == 0) continue;
        if (!mem[nx][ny]) dfs(nx, ny);
        sum += mem[nx][ny];
    }

    mem[x][y] = sum % MOD;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];

    dfs(1, 1);
    cout << mem[1][1] << endl;

    return 0;
}