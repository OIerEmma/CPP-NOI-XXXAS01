//
// Created by Emme.Kwok on 2026/9/7.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 505, K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
int a[N][N], n, m;
bool vis[N][N];
vector<pair<int, int>> point;

void dfs(int x, int y, int color) {
    vis[x][y] = true;
    point.push_back({x, y});
    for (int i = 0; i < K; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == color)
            dfs(nx, ny, color);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    set<string> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j]) {
                point.clear();
                dfs(i, j, a[i][j]);
                // 找方块中格子最小的行minr和列minc
                int minr = point[0].first, minc = point[0].second;
                for (int k = 1; k < point.size(); k++) {
                    minr = min(minr, point[k].first);
                    minc = min(minc, point[k].second);
                }
                // 对方块进行平移至左上方
                for (int k = 0; k < point.size(); k++)
                    point[k].first -= minr, point[k].second -= minc;
                // 对方块进行字典序排序(确保顺序稳定即保证形状相同)
                sort(point.begin(), point.end());
                // 形状哈希：x1,y1|x2,y2|...
                string shape;
                for (int k = 0; k < point.size(); k++)
                    shape += to_string(point[k].first) + "," + to_string(point[k].second) + "|";
                s.insert(shape);
            }
    cout << s.size() << endl;
    return 0;
}