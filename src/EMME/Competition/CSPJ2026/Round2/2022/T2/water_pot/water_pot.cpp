//
// Created by Geek.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0)
            return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};