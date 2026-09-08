//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

class Solution {
public:
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '0') {
                grid[nx][ny] = '0';
                dfs(nx, ny, n, m, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = (int)grid.size(), m = (int)grid[0].size();
        if (!n) return 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != '0') {
                    dfs(i, j, n, m, grid);
                    ans++;
                }
        return ans;
    }
};