//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        for (auto c : s) mp[c]++;
        for (auto c : t) {
            if (mp[c] <= 0) return false;
            mp[c]--;
        }
        return true;
    }
};