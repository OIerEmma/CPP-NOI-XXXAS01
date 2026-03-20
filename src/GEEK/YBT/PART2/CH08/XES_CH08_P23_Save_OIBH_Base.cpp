//
// Created by Geek.Kwok on 3/20/26.
#include <bits/stdc++.h>
using namespace std;

#define N 501

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, cnt;
bool vis[N][N];
char mp[N][N];

void dfs(int x, int y) {
    if (mp[x][y] == '0' && (x < 2 || mp[x-1][y] == '*') && (x > n - 1 || mp[x+1][y] == '*') && ( y > m - 1 || mp[x][y+1] == '*') && (y < 2 || mp[x][y-1] == '*')) {
        cnt++;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || mp[xx][yy] == '*' || vis[xx][yy]) continue;
        vis[xx][yy] = true;
        dfs(xx, yy);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    dfs(1, 1);
    cout << cnt << endl;
    return 0;
}