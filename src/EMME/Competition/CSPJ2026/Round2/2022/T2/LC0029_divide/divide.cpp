//
// Created by Geek.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int ans = 0;
        bool fu = (dividend < 0) != (divisor < 0);
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        while (dividend <= divisor) {
            int plan = divisor;
            int time = 1;
            while (time <= (INT_MAX >> 1) && plan >= dividend - plan) {
                plan += plan;
                time <<= 1;
            }
            dividend -= plan;
            ans -= time;
        }
        return fu ? ans : -ans;
    }
};