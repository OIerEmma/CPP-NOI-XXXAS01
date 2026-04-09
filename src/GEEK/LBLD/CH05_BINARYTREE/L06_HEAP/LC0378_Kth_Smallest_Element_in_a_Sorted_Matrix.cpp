//
// Created by Geek.Kwok on 4/9/26.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    priority_queue<int, vector<int>> pq;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        for (auto & m : matrix) {
            for (int ele : m) {
                pq.push(ele);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};