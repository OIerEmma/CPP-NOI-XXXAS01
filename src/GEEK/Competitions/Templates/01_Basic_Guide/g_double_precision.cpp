//
// Created by Geek.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

// 按比例取人数：前 i 人中 w% 获奖，至少 1 人（J20T2 直播获奖）
int winners(int i, int w) {
    return max(1, i * w / 100); // 整数除法就是向下取整，与题意 ⌊i×w%⌋ 一致
}

// 浮点比较：不要用 ==
const double EPS = 1e-9;

// 保留 k 位小数输出时，消除 "-0.00" eps 取 0.5×10^(-k)：k = 2 时取 0.005，k = 3 时取 0.0005
double fixZero(double x, double eps) {
    return fabs(x) < eps ? 0.0 : x;
}

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