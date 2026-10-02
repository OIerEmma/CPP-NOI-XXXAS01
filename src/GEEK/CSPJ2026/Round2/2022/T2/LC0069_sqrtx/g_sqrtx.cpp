//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("g_sqrtx.in", "r", stdin);
    freopen("g_sqrtx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 下面开始写本题
    return 0;
}

class Solution {
public:
    int mySqrt(int x) {
        long long r = 1;
        while (r * r > x) r--;
        while ((r + 1) * (r + 1) <= x) r++;
        return (int)r;
    }
};