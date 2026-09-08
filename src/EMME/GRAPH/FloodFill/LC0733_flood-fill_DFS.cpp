//
// Created by Emme.Kwok on 2026/9/4.
//
#include<bits/stdc++.h>
using namespace std;

const int K = 4;
const int dx[K] = {-1, 1, 0, 0};
const int dy[K] = {0, 0, -1, 1};

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int cur) {
        image[sr][sc] = color;
        for (int i = 0; i < K; i++) {
            int nx = sr + dx[i], ny = sc + dy[i];
            if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == cur)
                dfs(image, nx, ny, color, cur);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int cur = image[sr][sc];
        if (color != cur) dfs(image, sr, sc, color, cur);
        return image;
    }
};