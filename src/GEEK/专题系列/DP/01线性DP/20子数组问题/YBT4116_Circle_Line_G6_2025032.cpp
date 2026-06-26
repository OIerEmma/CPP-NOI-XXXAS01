//
// Created by Geek.Kwok on 6/26/26.
//
#include <bits/stdc++.h>
using namespace std;

// --- 前缀和 + 单调队列 ---

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入数据
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];  // 破环成链，复制一倍

    // 核心算法：前缀和 + 单调队列
    // 构建前缀和数组pre
    vector<long long> pre(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
    // 单调队列q
    deque<int> q; q.push_back(0);
    long long ans = -1e18;
    // 单调队列：从暴力枚举O(n^2)优化到O(n)
    for (int i = 1; i <= 2 * n; i++) {
        while (!q.empty() && q.front() < i - n) q.pop_front();      // 最大窗口为n，移除过远的起点
        ans = max(ans, pre[i] - pre[q.front()]);                // 前缀和之差取最大值
        while (!q.empty() && pre[i] < pre[q.back()]) q.pop_back();  // 维护单调递增
        q.push_back(i);
    }

    // 结果：最大子段和 = 前缀和之差取最大值
    cout << ans << endl;
    return 0;
}