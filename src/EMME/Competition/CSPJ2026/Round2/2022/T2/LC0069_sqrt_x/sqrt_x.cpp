//
// Created by Emme.Kwok on 2026/10/1.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long r = 0;
        while ((r + 1) * (r + 1) <= x) r++;
        while (r * r > x) r--;
        return r;
    }
};