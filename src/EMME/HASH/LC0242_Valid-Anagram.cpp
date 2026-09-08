//
// Created by Emme.Kwok on 2026/9/8.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for (int i = 0; i < t.size(); i++) {
            if (mp[t[i]] <= 0) return false;
            mp[t[i]]--;
        }
        return true;
    }
};