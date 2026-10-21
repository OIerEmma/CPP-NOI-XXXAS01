//
// Created by Emme.Kwok on 2026/10/9.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = (int)arr.size();
        vector<int> preXor(n + 1, 0);
        for (int i = 1; i <= n; i++) preXor[i] = preXor[i - 1] ^ arr[i - 1];
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
            res.push_back(preXor[queries[i][1] + 1] ^ preXor[queries[i][0]]);
        return res;
    }
};