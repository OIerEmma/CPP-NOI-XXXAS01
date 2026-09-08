//
// Created by Emme.Kwok on 2026/9/8.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        long long pre = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            ans += mp[pre - k];
            mp[pre]++;
        }
        return ans;
    }
};