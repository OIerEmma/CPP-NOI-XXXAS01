//
// Created by Emme.Kwok on 2026/7/22.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int hold = -1e4, sold = 0;
        for (int i = 0; i < n; i++) {
            hold = max(hold, -prices[i]);
            sold = max(sold, hold + prices[i]);
        }
        return sold;
    }

    int maxProfit2(vector<int>& prices) {
        int n = (int)prices.size();
        int maxp = 0, minp = 1e9;
        for (int i = 0; i < n; i++) {
            maxp = max(maxp, prices[i] - minp);
            minp = min(minp, prices[i]);
        }
        return maxp;
    }
};