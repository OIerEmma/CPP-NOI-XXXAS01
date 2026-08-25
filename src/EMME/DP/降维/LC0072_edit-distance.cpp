//
// Created by Emme.Kwok on 2026/8/24.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.size(), m = (int)word2.size();
        vector<int> pre(m + 1, 0), cur(m + 1, 0);
        for (int i = 0; i <= n; i++) pre[i] = i;
        for (int j = 0; j <= m; j++) pre[j] = j;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int x = pre[j - 1];
                if (word1[i - 1] != word2[j - 1]) x++;
                cur[j] = min(cur[j - 1] + 1, min(x, pre[j] + 1));
            }
        return pre[m];
    }
};