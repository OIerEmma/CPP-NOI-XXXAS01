//
// Created by Emme.Kwok on 2026/3/16.
//
#include<iostream>
#include<cstring>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, cnt = 1;
char mp[25][25];
bool vis[25][25];

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = dx[i] + x, yy = dy[i] + y;
        if (xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || mp[xx][yy] == '#') continue;
        vis[xx][yy] = true;
        cnt++;
        dfs(xx, yy);
    }
}

int main() {
    while (true) {
        cin >> m >> n;
        if (n == 0 && m == 0) {
            break;
        }
        cnt = 1;
        memset(vis, false, sizeof(vis));
        int x = -1, y = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == '@') {
                    x = i, y = j;
                }
            }
        }
        vis[x][y] = true;
        dfs(x, y);
        cout << cnt << endl;
    }
    return 0;
}