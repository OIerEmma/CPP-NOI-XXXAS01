//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit: num) {
            while (!stk.empty() && stk.back() > digit && k) stk.pop_back(), k--;
            stk.push_back(digit);
        }
        while (k--) stk.pop_back();
        string ans;
        bool flag = true;
        for (auto& digit: stk) {
            if (flag && digit == '0') continue;
            flag = false;
            ans += digit;
        }
        return ans.empty() ? "0" : ans;
    }
};