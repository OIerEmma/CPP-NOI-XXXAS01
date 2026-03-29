//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <vector>
#include "MyMonotonicQueue.cpp"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyMonotonicQueue window;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                // 先把窗口的前 k-1 填满
                window.push(nums[i]);
            } else {
                // 窗口开始向前滑动
                // 移入新元素
                window.push(nums[i]);
                // 将当前窗口中的最大元素记入结果
                res.push_back(window.max());
                // 移出最后的元素
                window.pop(nums[i - k + 1]);
            }
        }

        return res;
    }
};

int main() {
    return 0;
}