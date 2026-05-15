//
// Created by Geek.Kwok on 5/15/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> c[i][0] >> c[i][1];
    sort(c.begin(), c.end());
    // 初始化
    vector<int> tails;
    // 计算顺序
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), c[i][1]);
        if (it == tails.end()) tails.push_back(c[i][1]);
        else *it = c[i][1];
    }
    // 返回结果
    cout << tails.size() << endl;
    return 0;
}