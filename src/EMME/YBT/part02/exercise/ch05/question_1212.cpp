//
// Created by Emme.Kwok on 2026/1/3.
//
#include<iostream>
#include<map>
using namespace std;

int r, s, res;
char c[25][25];
map<char, int> m;
bool vis[25][25];
const int dx[] = {1, -1, 0, 0},
          dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
    res = max(res, (int)m.size());

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i], newY = y + dy[i];
        if (newX >= 1 && newX <= r && newY >= 1 && newY <= s && !vis[newX][newY] && !m.count(c[newX][newY])) {
            m[c[newX][newY]] = 1;
            vis[newX][newY] = true;
            dfs(newX, newY);
            vis[newX][newY] = false;
            m.erase(c[newX][newY]);
        }
    }
}

int main() {
    cin >> r >> s;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= s; j++) {
            cin >> c[i][j];
        }
    }
    vis[1][1] = true;
    m[c[1][1]] = 1;
    dfs(1, 1);
    cout << res << endl;
    return 0;
}