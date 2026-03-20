//
// Created by Geek.Kwok on 3/20/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 1001
#define MOD 998244353

int n, m, mp[N][N], s[N][N];

int dfs(int x, int y) {
    if (s[x][y] != -1) return s[x][y];
    if (x == n && y == m) return 1;
    if (mp[x][y] == 0) return 0;
    long long cnt = 0;
    for (int i = 1; i <= mp[x][y]; i++) {
        int xx = x + i, yy = y;
        if (xx > n || yy > m || mp[xx][yy] == 0) continue;
        cnt += dfs(xx, yy);
    }
    for (int j = 1; j <= mp[x][y]; j++) {
        int xx = x, yy = y + j;
        if (xx > n || yy > m || mp[xx][yy] == 0) continue;
        cnt += dfs(xx, yy);
    }
    return s[x][y] = int(cnt % MOD);
}

/**
 * AC.
 */
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &mp[i][j]);
    memset(s, -1, sizeof s);
    printf("%d\n", dfs(1, 1));
    return 0;
}