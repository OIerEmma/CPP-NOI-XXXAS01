//
// Created by Emme.Kwok on 2026/8/22.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> g[100005];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans;
        for (int i = 1; i <= edges.size() + 1; i++)
            if (g[i].size() == edges.size()) { ans = i; break; }
        return ans;
    }
};