//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static const int K = 4, N = 55, M = 55;
    const int dx[K] = {0, 0, -1, 1};
    const int dy[K] = {-1, 1, 0, 0};
    bool vis[N][M];
    int area = 1;
    int dfs(vector<vector<int>>& grid, int x, int y, int n, int m) {
        vis[x][y] = true;
        for (int i = 0; i < K; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny])
                dfs(grid, nx, ny, n, m), area++;
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, false, sizeof vis);
        int n = (int)grid.size(), m = (int)grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && grid[i][j])
                    area = 1, ans = max(ans, dfs(grid, i, j, n, m));
        return ans;
    }
};