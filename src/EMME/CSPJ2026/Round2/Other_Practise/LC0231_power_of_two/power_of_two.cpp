//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        double num = log2(n);
        return (int)num == num;
    }
};