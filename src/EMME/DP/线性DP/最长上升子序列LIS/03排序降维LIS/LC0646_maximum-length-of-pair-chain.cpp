//
// Created by Emme.Kwok on 2026/5/30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     int n = pairs.size();
    //     vector<int> dp(n, 1);
    //     sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
    //         return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    //     });
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (pairs[j][1] < pairs[i][0])
    //                 dp[i] = max(dp[j] + 1, dp[i]);
    //         }
    //         ans = max(dp[i], ans);
    //     }
    //     return ans;
    // }
    // int findLongestChain(vector<vector<int>>& pairs) {
    //     int n = pairs.size();
    //     sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
    //         return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    //     });
    //     int last = -1001, cnt = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (last < pairs[i][0])
    //             cnt++, last = pairs[i][1];
    //     }
    //     return cnt;
    // }
    // 标准DP：O(n2)
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        // 按照第1个数字从小到大排序
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};