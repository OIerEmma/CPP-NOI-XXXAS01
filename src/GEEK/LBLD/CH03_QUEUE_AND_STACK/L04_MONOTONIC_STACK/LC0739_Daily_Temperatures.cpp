//
// Created by Geek.Kwok on 2026/3/29.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std ;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        // 这里放元素索引，而不是元素
        stack<int> s;
        // 单调栈模版
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            // 得到索引间距
            res[i] = s.empty() ? 0 : (s.top() - i);
            // 将索引入栈，而不是元素
            s.push(i);
        }
        return res;
    }
};

int main() {

    return 0;
}