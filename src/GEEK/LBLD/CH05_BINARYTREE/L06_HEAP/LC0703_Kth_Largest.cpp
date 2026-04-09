//
// Created by Geek.Kwok on 4/9/26.
//
#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) {
        // 将 nums 装入小顶堆，保留下前 k 大的元素
        for (int e: nums) {
            heap.push(e);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        this->k = k;
    }

    int add(int val) {
        // 维护小顶堆只保留前 k 大的元素
        heap.push(val);
        if (heap.size() > k) {
            heap.pop();
        }
        // 堆顶就是第 k 大元素（即倒数第 k 小的元素）
        return heap.top();
    }
};
