//
// Created by Geek.Kwok on 2026/5/15.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输出
    int n = 0, arr[100010];
    // cin >> n; for (int i = 0; i < n; i++) cin >> arr[i];
    while (cin >> arr[n++]);
    // t1[i] 长度为i+1的递增子序列，它的末尾数的最小值
    // t2[i] 长度为i+1的不递增子序列，它的末尾数的最大值
    vector<int> t1, t2;
    for (int i = 0; i < n; i++) {
        // 在t1数组里二分查找第一个大于等于x的位置
        auto it = lower_bound(t1.begin(), t1.end(), arr[i]);
        if (it == t1.end()) t1.push_back(arr[i]); // x比所有末尾都大则延长队伍
        else *it = arr[i]; // 否则替换掉那个位置，让末尾更小（贪心：同样长度的递增序列，末尾越小，队伍长度才可能更大）

        // 在t2数组里二分查找第一个小于x的位置，greater 在降序数组中查找
        auto it2 = upper_bound(t2.begin(), t2.end(), arr[i], greater<int>());
        if (it2 == t2.end()) t2.push_back(arr[i]); // x比所有末尾都小则延长队伍
        else *it2 = arr[i]; // 否则替换掉那个位置，让末尾更大（贪心：同样长度的不递增序列，末尾越大，队伍长度才可能更大）
    }
    cout << t2.size() << endl << t1.size() << endl;
    return 0;
}