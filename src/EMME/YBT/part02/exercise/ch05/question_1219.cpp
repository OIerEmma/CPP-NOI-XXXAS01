//
// Created by Emme.Kwok on 2026/3/17.
//
#include<iostream>
#include<cstring>
using namespace std;

const int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
const int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
bool vis[15][15];
int n, m, x, y, t, res;

void dfs(int x, int y, int cnt) {
    if (cnt == n * m) {
        res++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) continue;
        vis[xx][yy] = true;
        dfs(xx, yy, cnt + 1);
        vis[xx][yy] = false;
    }
}

int main() {
    cin >> t;
    while (t--) {
        res = 0;
        memset(vis, false, sizeof vis);
        cin >> n >> m >> x >> y;
        vis[x][y] = true;
        dfs(x, y, 1);
        cout << res << endl;
    }
    return 0;
}