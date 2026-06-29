//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];
    // 核心算法：前缀和+单调队列
    vector<long long> pre(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
    deque<int> q;
    q.push_back(0);
    long long ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        while (!q.empty() && q.front() < i - n) q.pop_front();
        ans = max(ans, pre[i] - pre[q.front()]);
        while (!q.empty() && pre[i] < pre[q.back()]) q.pop_back();
        q.push_back(i);
    }
    cout << ans << endl;
    return 0;
}