//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Soltion {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 记录 nums2 中每个元素的下一个更大元素
        vector<int> greater = calculateGreaterElement(nums2);
        // 转化成映射：元素 x -> x的下一个最大元素
        unordered_map<int, int> greaterMap;
        for (int i = 0; i < nums2.size(); i++) {
            greaterMap[nums2[i]] = greater[i];
        }
        // nums1 是 nums2 的子集，所以根据 greaterMap 可以得到结果
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = greaterMap[nums1[i]];
        }
        return res;
    }

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
};

int main() {

    return 0;
}