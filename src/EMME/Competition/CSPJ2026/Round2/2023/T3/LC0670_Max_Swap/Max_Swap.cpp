//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = (int)s.size(), maxNum = num;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                swap(s[i], s[j]);
                maxNum = max(maxNum, stoi(s));
                swap(s[i], s[j]);
            }
        return maxNum;
    }
};