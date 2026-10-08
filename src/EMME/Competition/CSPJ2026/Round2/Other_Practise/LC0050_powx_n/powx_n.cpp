//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double qpow(double a, long long b) {
        double ans = 1;
        while (b) {
            if (b & 1) ans = ans * a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }
    double myPow(double x, long long n) {
        bool flag = true;
        if (n < 0) flag = false, n = -n;
        double ans = qpow(x, n);
        if (!flag) ans = 1.0 / ans;
        ans = (int)(ans * 100000) / 100000.0;
        return ans;
    }
};