//
// Created by Emme.Kwok on 2026/8/27.
//
#include<bits/stdc++.h>
using namespace std;

const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};

class Solution {
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] != 1) return 0;
        grid[x][y] = 0;
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + di[i], ny = y + dj[i];
            ans += dfs(grid, nx, ny);
        }
        return ans;
    }
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); i++)
            for (int j = 0; j != grid[0].size(); j++)
                ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};