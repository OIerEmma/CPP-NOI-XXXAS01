//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
    map<int, int> t;
public:
    int distributeCandies(vector<int>& candyType) {
        int n = (int)candyType.size();
        for (int c : candyType) t[c]++;
        return min((int)t.size(), n / 2);
    }
};