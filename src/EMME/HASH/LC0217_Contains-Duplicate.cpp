//
// Created by Emme.Kwok on 2026/9/8.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.count(i)) return true;
            s.insert(i);
        }
        return false;
    }
};