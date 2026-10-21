//
// Created by Emme.Kwok on 2026/10/10.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i = 1; i * i <= num; i++)
            if (i * i == num) return true;
        return false;
    }
};