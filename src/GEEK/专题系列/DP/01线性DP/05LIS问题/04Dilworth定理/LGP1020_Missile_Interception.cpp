//
// Created by Geek.Kwok on 2026/5/15.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int x;
    vector<int> arr, t1, t2;
    while (cin >> x) { arr.push_back(x); }
    // t1[i] 长度为i+1的不递增子序列，它的末尾数的最大值
    // t2[i] 长度为i+1的递增子序列，它的末尾数的最小值
    for (int a: arr) {
        // 在t1数组里二分查找第一个小于x的位置
        auto it1 = upper_bound(t1.begin(), t1.end(), a, greater<int>());
        if (it1 == t1.end()) t1.push_back(a); // ：x比所有末尾都小则延长队伍
        else *it1 = a; // 否则替换掉那个位置，让末尾更大（贪心：同样长度的不递增序列，末尾越大，队伍长度才可能更大）

        // 在t2数组里二分查找第一个大于等于x的位置
        auto it2 = lower_bound(t2.begin(), t2.end(), a);
        if (it2 == t2.end()) t2.push_back(a); // x比所有末尾都大则延长队伍
        else *it2 = a; // 否则替换掉那个位置，让末尾更小（贪心：同样长度的递增序列，末尾越小，队伍长度才可能更大）
    }
    cout << t1.size() << endl << t2.size() << endl;
    return 0;
}