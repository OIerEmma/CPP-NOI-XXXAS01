//
// Created by Geek.Kwok on 3/16/26.
//
#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int t, n, m, x, y, cnt;
bool visited[10][10];

void dfs(int x, int y, int num) {
    if (num == n * m) {
        cnt++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= n || yy >= m || xx < 0 || yy < 0 || visited[xx][yy]) continue;
        visited[xx][yy] = true;
        dfs(xx, yy, num + 1);
        visited[xx][yy] = false;
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        cnt = 0;
        memset(visited, false, sizeof(visited));
        visited[x][y] = true;
        dfs(x, y, 1);
        cout << cnt << endl;
    }
    return 0;
}