//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateGreaterElement(vector<int>& nums) {
    int n = nums.size();
    // 存放答案的数组
    vector<int> res(n);
    stack<int> s;
    // 倒着往栈里放
    for (int i = n - 1; i >= 0; i--) {
        // 判定个子高矮
        while (!s.empty() && s.top() <= nums[i]) {
            // 矮个起开，反正也被挡着了...
            s.pop();
        }
        // nums[i]身后的更大元素
        res[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return res;
}

int main() {
    return 0;
}