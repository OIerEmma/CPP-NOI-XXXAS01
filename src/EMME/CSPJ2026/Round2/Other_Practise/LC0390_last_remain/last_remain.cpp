//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int l = 1, size = n;
        for (int i = 1, s = 1; size > 1; size /= 2, i = !i, s *= 2)
            l += i || size & 1 ? s : 0;
        return l;
    }
};