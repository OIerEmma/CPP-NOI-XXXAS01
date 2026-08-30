//
// Created by Emme.Kwok on 2026/8/26.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int> &target, vector<int> &arr) {
        int n = (int)target.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) pos[target[i]] = i;
        vector<int> tails;
        for (int val : arr)
            if (pos.count(val)) {
                int idx = pos[val];
                auto it = lower_bound(tails.begin(), tails.end(), idx);
                if (it != tails.end()) *it = idx;
                else tails.push_back(idx);
            }
        return n - (int)tails.size();
    }
};