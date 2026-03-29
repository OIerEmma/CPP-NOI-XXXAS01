//
// Created by Emme.Kwok on 2026/3/25.
//
#include<iostream>
using namespace std;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int mp[55][55], cnt, ans, maxv = -1, n, m;
bool vis[55][55];

void dfs(int x, int y) {
    vis[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[x][y] >> i & 1) continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                ans++;
                cnt = 0;
                dfs(i, j);
                maxv = max(cnt, maxv);
            }
        }
    }
    cout << ans << endl << maxv << endl;
    return 0;
}