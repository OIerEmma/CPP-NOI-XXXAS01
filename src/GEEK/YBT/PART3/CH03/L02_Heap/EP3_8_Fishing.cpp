//
// Created by Geek.Kwok on 2026/4/8.
//
#include <iostream>
using namespace std;

struct Data {
    int fish, lake; // 堆中节点的信息
}heap[101];

int t[101], f[101], d[101];
int Max, k, t1;

void maintain(int i) {
    Data a;
    int next;
    a = heap[i];
    next = 2 * i;
    while (next <= k) {
        if (next < k && heap[next].fish < heap[next+1].fish) next++;
        if (a.fish < heap[next].fish) {
            heap[i] = heap[next];
            i = next;
            next *= 2;
        } else break;
    }
    heap[i] = a;
}

void work() {
    int i, j, m, n;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> f[i];
    for (i = 1; i <= n; i++) cin >> d[i];
    for (i = 1; i < n; i ++) cin >> t[i];
    cin >> m;

    for (k = 1; k <= n; k++) { // 枚举最远走到的池塘的编号
        int Time = m - t1; // 计算剩余时间
        int ans = 0;
        for (i = 1; i <= k; i++) { // 收集能够钓鱼的池塘的资料
            heap[i].fish = f[i];
            heap[i].lake = i;
        }
        for (i = 1; i <= k/2; i ++) maintain(i); // 堆的初始化
        while (Time > 0 && heap[1].fish > 0) {
            ans += heap[1].fish; // 贪心选取鱼最多的池塘
            heap[1].fish -= d[heap[1].lake]; // 修改鱼的数量
            maintain(1); // 堆维护
            Time--; // 剩余时间变少
        }
        if (ans > Max) Max = ans; // 刷新最优解
        t1 += t[k]; // 累计走路需要的时间
    }
    cout << Max << endl;
}

int main() {
    // freopen("fishing.in", "r", stdin);
    // freopen("fishing.out", "w", stdout);
    work();
    return 0;
}