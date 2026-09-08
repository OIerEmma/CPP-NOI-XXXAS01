//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int K = 4, N = 505, M = 505;
    const int dx[K] = {-1, 1, 0, 0};
    const int dy[K] = {0, 0, -1, 1};
    int ans;
    bool vis[N][M];
    void dfs(vector<vector<char>>& board, int x, int y, int n, int m) {
        vis[x][y] = true;
        for (int k = 0; k < K; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == 'O')
                dfs(board, nx, ny, n, m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = (int)board.size(), m = (int)board[0].size();
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') dfs(board, 0, j, n, m);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') dfs(board, n - 1, j, n, m);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') dfs(board, i, 0, n, m);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
    }
};