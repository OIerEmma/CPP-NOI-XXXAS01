//
// Created by Geek.Kwok on 2026/10/4.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char sign = '+';
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) num = num * 10 + int(s[i] - '0');
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                switch (sign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                sign = s[i];
                num = 0;
            }
        }
        int ans = 0;
        for (int x : stk) ans += x;
        return ans;
    }
};