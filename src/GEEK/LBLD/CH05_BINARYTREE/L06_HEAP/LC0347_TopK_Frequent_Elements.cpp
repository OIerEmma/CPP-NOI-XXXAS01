//
// Created by Geek.Kwok on 4/9/26.
//
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    map<int, int> mp;
    struct MAP_CMP {
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
            return p1.second < p2.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, MAP_CMP> pq;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int n: nums) {
            mp[n] = mp[n] ? mp[n] + 1 : 1;
        }
        for (auto p: mp) {
            pq.emplace(p);
        }
        vector<int> ans;
        for (int i = 1; i <= k; i++) {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.first);
        }
        return ans;
    }
};

int main() {

    return 0;
}