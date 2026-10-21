//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[15] = {false}, res = 0;
    void dfs(int step, int start, int size, vector<int> &nums) {
        if (step == size) {
            int ans = 0;
            // for (int i = 0; i < nums.size(); i++)
            //     if (vis[i]) cout << nums[i] << " ";
            // cout << endl;
            for (int i = 0; i < nums.size(); i++)
                if (vis[i]) ans ^= nums[i];
            res += ans;
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(step + 1, i + 1, size, nums);
                vis[i] = false;
            }
        }
    }
    int subsetXORSum(vector<int>& nums) {
        res = 0;
        int n = (int)nums.size();
        for (int i = 1; i <= n; i++) {
            memset(vis, false, sizeof vis);
            dfs(0, 0, i, nums);
        }
        return res;
    }
};