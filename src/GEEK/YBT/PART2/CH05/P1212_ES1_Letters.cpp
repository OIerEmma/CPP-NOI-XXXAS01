//
// Created by Geek.Kwok on 3/17/26.
//
#include <bits/stdc++.h>
using namespace std;

#define N 30
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int row, col, cnt;
bool vis[N][N];
char a[N][N];
set<char> letters;

void dfs(int x, int y, int step) {
    if (step >= row * col) {
        cnt = max(cnt, (int)letters.size());
        return;
    }
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > row || yy < 1 || yy > col || vis[xx][yy] || letters.count(a[xx][yy])) continue;
        vis[xx][yy] = true;
        letters.insert(a[xx][yy]);
        dfs(xx, yy, step + 1);
        vis[xx][yy] = false;
        letters.erase(a[xx][yy]);
    }
}

int main() {
    cin >> row >> col;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> a[i][j];
        }
    }
    vis[1][1] = true;
    letters.insert(a[1][1]);
    dfs(1, 1, 1);
    cout << cnt << endl;
    return 0;
}