//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int ans = num;
        while (ans >= 10) {
            int t = ans;
            ans = 0;
            while (t) {
                ans += t % 10;
                t /= 10;
            }
        }
        return ans;
    }
};