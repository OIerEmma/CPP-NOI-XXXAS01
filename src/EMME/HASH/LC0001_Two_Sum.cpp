//
// Created by Emme.Kwok on 2026/9/8.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int x = -1, y = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i])) {
                x = i, y = mp[target - nums[i]];
                break;
            }
            mp[nums[i]] = i;
        }
        return {x, y};
    }
};