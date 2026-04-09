//
// Created by Geek.Kwok on 2026/4/8.
//
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> heap;
int t[101], f[101], d[101];
int ans, m, Max, n, k, t1, Time;

void work() {
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> f[i];
    for (i = 1; i <= n; i++) cin >> d[i];
    for (i = 1; i < n; i++) cin >> t[i];
    cin >> m;
    for (k = 1; k <= n; k++) { // 枚举最远走到的池塘的编号
        Time = m - t1; // 计算剩余时间
        ans = 0;
        for (i = 1; i <= k; i++) // 收集能够钓鱼的池塘的资料
            heap.emplace(f[i], i);
        while (Time > 0 && heap.top().first > 0) {
            pair<int, int> a = heap.top();
            heap.pop();
            ans += a.first; // 贪心选取鱼最多的池塘
            a.first -= d[a.second]; // 修改鱼的数量
            heap.push(a); // 堆维护
            Time--; // 剩余时间变少
        }
        if (ans > Max) Max = ans; // 刷新最优解
        t1 += t[k]; // 累计走路需要的时间
    }
    cout << Max << endl;
}

int main() {
    work();
    return 0;
}