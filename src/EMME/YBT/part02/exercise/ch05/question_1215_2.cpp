//
// Created by Emme.Kwok on 2026/3/15.
//
#include<iostream>
#include<cstring>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int t, n, ha, la, hb, lb;
bool vis[105][105];
char mp[105][105];
bool flag = false;

void dfs(int x, int y) {
    if (x == hb && y == lb) {
        printf("YES\n");
        flag = true;
        return;
    }
    if (flag) return;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx > n - 1 || yy < 0 || yy > n - 1 || vis[xx][yy] || mp[xx][yy] == '#') continue;
        vis[xx][yy] = true;
        dfs(xx, yy);
        vis[xx][yy] = false;
    }
}

int main() {
    cin >> t;
    while (t--) {

    }
    return 0;
}
