//
// Created by Geek.Kwok on 2026/5/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 505;         // 最大道具数
const int MAXA = N * 505;  // 最大总攻击力
const int INF = 1e9 + 10;

int n, k;
int f[MAXA];  // f[j]：达到攻击力j的最小花费

int main() {
    cin >> n >> k;
    vector<int> a(n), c(n);
    int totalA = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        totalA += a[i];
    }

    // 初始化为无穷大
    for (int i = 1; i < MAXA; i++)
        f[i] = INF;
    f[0] = 0;

    // 状态转移过程
    for (int i = 0; i < n; i++) {
        // 0-1背包：反向更新，价值维度作为容量
        for (int j = totalA; j >= a[i]; j--)
            f[j] = min(f[j], f[j - a[i]] + c[i]);
    }

    // 寻找花费 <= k 的最大攻击力
    int ans = 0;
    for (int i = totalA; i >= 0; i--)
        if (f[i] <= k) {
            ans = i; break;
        }

    cout << ans << endl;
    return 0;
}