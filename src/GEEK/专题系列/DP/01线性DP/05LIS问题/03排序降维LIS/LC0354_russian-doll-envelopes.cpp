//
// Created by Geek.Kwok on 5/30/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool static cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> tails;
        for (int i = 0; i < envelopes.size(); i++) {
            auto it = lower_bound(tails.begin(), tails.end(), envelopes[i][1]);
            if (it == tails.end()) tails.push_back(envelopes[i][1]);
            else *it = envelopes[i][1];
        }
        return tails.size();
    }
};