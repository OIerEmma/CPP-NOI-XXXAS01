//
// Created by Emme.Kwok on 2026/8/26.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int ans = 0;
        map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }
};