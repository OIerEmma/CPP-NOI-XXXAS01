//
// Created by Emme.Kwok on 2026/4/18.
//
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int left_bound(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        if (left < 0 || left > nums.size() - 1) return -1;
        return nums[left] == target ? left : -1;
    }
    int right_bound(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (right < 0 || right > nums.size() - 1) return -1;
        return nums[right] == target ? right : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        vector<int> res;
        res.push_back(left_bound(nums, target));
        res.push_back(right_bound(nums, target));
        return res;
    }
};

