//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

int main() {
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // ...解题...
    return 0;
}

// 3 二进制枚举子集：n 个物品（n ≤ 20），mask 的第 i 位为 1 表示选第 i 个
void enumSubsets(int n, const int a[]) {
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1) sum += a[i];
    }
}