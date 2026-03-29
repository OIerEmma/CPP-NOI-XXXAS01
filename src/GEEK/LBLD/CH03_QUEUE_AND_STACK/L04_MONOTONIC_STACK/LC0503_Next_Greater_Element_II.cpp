//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        // 数组长度加倍模拟环形数组
        for (int i = 2*n - 1; i >= 0; i--) {
            // 索引 i 要求模，其他的和模版一样
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            res[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i % n]);
        }
        return res;
    }
};

int main() {
    return 0;
}