//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static const int K = 4, N = 105, M = 105;
    const int dx[K] = {0, 1, 0, -1};
    const int dy[K] = {1, 0, -1, 0};
    bool vis[N][M];
public:
    int dfs(vector<vector<int>> &grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || grid[x][y] == 0) return 0;
        vis[x][y] = true;
        int p = 0;
        for (int i = 0; i < K; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny]) p += dfs(grid, nx, ny, n, m);
            else p++;
        }
        return p;
    }
    int islandPerimeter(vector<vector<int>> &grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    ans += dfs(grid, i, j, n, m);
        return ans;
    }
};