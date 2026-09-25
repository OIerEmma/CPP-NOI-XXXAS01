//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

bool cmp(string &s, string &t) {
    return s + t > t + s;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (int i : nums) s.push_back(to_string(i));
        sort(s.begin(), s.end(), cmp);
        string ans;
        for (string& t : s) ans += t;
        while (ans[0] == '0' && ans.size() > 1) ans.erase(0, 1);
        return ans;
    }
};