//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[55][55] = {{false}};
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    struct node {
        int x, y;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        queue<node> q;
        q.push({sr, sc});
        int cur = image[sr][sc];
        vis[sr][sc] = true;
        image[sr][sc] = color;
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && !vis[nx][ny] && image[nx][ny] == cur) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
        return image;
    }
};