//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
struct node {
    int x, y;
};

class Solution {
public:
    void bfs(int x, int y, int n, int m, vector<vector<char>>& grid) {
        queue<node> q;
        q.push({x, y});
        grid[x][y] = '0';
        while (!q.empty()) {
            node u = q.front(); q.pop();
            for (int i = 0; i < K; i++) {
                int nx = u.x + dx[i], ny = u.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '0') {
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = (int)grid.size(), m = (int)grid[0].size();
        if (!n) return 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != '0')
                    bfs(i, j, n, m, grid), ans++;
        return ans;
    }
};