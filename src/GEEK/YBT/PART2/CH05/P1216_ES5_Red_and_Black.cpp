//
// Created by Geek.Kwok on 2026/3/15.
//
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int w, h, x, y, cnt;
char mp[21][21];
bool vis[21][21];

void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > h || yy < 1 || yy > w || mp[xx][yy] == '#' || vis[xx][yy]) continue;
        vis[xx][yy] = 1;
        cnt++;
        dfs(xx, yy);
        // vis[xx][yy] = 0; 不需要回溯
    }
}

int main() {
    do {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> mp[i][j];
                if (mp[i][j] == '@') {
                    x = i, y = j;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        cnt = 1, vis[x][y] = 1;
        dfs(x, y);
        cout << cnt << endl;
    } while (true);
    return 0;
}