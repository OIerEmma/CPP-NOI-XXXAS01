//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};
bool vis[55][55];
struct node {
    int x, y;
};

class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(vis, false, sizeof vis);
        queue<node> q;
        q.push({sr, sc});
        int cur = image[sr][sc];
        vis[sr][sc] = true;
        image[sr][sc] = color;
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            for (int i = 0; i < K; i++) {
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && !vis[nx][ny] && image[nx][ny] == cur) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        bfs(image, sr, sc, color);
        return image;
    }
};