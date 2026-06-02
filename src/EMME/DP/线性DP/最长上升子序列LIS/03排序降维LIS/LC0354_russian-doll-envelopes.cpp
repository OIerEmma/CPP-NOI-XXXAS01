//
// Created by Emme.Kwok on 2026/5/30.
//
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> tails;
        int n = envelopes.size();
        for (int i = 0; i < n; i++) {
            auto x = lower_bound(tails.begin(), tails.end(), envelopes[i][1]);
            if (x == tails.end()) tails.push_back(envelopes[i][1]);
            else *x = envelopes[i][1];
        }
        return tails.size();
    }
};