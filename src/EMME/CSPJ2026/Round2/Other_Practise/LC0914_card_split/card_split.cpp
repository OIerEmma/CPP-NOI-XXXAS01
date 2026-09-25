//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mp[10005] = {};
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = (int)deck.size();
        for (int x : deck) mp[x]++;
        vector<int> values;
        for (int i = 0; i < 10000; i++)
            if (mp[i]) values.emplace_back(mp[i]);
        for (int x = 2; x <= n; x++)
            if (n % x == 0) {
                bool flag = true;
                for (int v : values)
                    if (v % x) { flag = false; break; }
                if (flag) return true;
            }
        return false;
    }
};