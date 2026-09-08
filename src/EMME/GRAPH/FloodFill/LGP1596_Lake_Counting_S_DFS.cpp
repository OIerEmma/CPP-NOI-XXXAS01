//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 105, K = 8;
const int dx[K] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[K] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n, m, ans;
bool vis[N][N];
char a[N][N];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < K; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == 'W')
            dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'W' && !vis[i][j])
                ans++, dfs(i, j);
    cout << ans << endl;
    return 0;
}