//
// Created by Geek.Kwok on 2026/9/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> cnt;
        long long pre = 0, ans = 0;
        cnt[0] = 1; // 空前缀
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            ans += cnt[pre - k]; // 满足 pre[l-1] = pre[r] - k 的个数
            cnt[pre]++; // 先查再插
        }
        return (int) ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<long long, long long> cnt;
    long long pre = 0, ans = 0;
    cnt[0] = 1; // 空前缀
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pre += x;
        ans += cnt[pre-k]; // 满足 pre[l-1] = pre[r] - k 的个数
        cnt[pre]++; // 先查再插
    }
    return 0;
}