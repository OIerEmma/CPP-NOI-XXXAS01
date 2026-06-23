//
// Created by Geek.Kwok on 6/23/26.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
vector<int> nums(N), tmp(N);

// 归并[l, r): 返回区间内顺序对(握手)数，并把区间排成降序
long long merge(int l, int r) {
    if (l + 1 == r) return 0; // 只剩一个元素则无对子
    int m = (l + r) / 2;
    long long res = merge(l, m) + merge(m, r); // 治：两半内部的对数
    // 合：拉链式合并两个降序半区，同时数跨半对子
    for (int i = l, j = m, k = l; k < r; k++) {
        if (j == r || (i < m && nums[i] > nums[j])) {
            tmp[k] = nums[i]; i++; // 取左半区较大者，不计数
        } else {
            tmp[k] = nums[j]; j++; // 取右半区较大者
            res += m - i;          // 左半剩余元素都比它小 -> 都握手
        }
    }
    for(int k = l; k < r; k++) nums[k] = tmp[k]; // 写回
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << merge(0, n) << endl;
    return 0;
}