//
// Created by Geek.Kwok on 2026/5/14.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
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

    // 贪心：O(nlogn)
    int findLongestChain2(vector<vector<int>>& pairs) {
        int n = pairs.size();
        // 按照第2个数字从小到大排序
        sort(pairs.begin(), pairs.end(), [](const vector<int> a, const vector<int> b) {
            return a[1] < b[1];
        });
        int lastEnd = pairs[0][1], count = 1;
        for (int i = 1; i < n; i++)
            if (pairs[i][0] > lastEnd)
                count++, lastEnd = pairs[i][1];
        return count;
    }
};

int main() {

}