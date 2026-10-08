//
// Created by Geek.Kwok on 2026/10/7.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
long long a[MAXN], b[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] *= i * (n - i + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    // 重排 a[] b[] 序列
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, greater<long long>());
    // 求和 s
    long long s = 0;
    for (int i = 1; i <= n; i++)
        s += a[i] * b[i];
    cout << s << endl;
    return 0;
}

/**
样例一：
输入
3
1 7 8
9 7 2
输出
251

样例二：
输入
8
3 5 6 4 7 7 6 1
4 1 3 8 6 1 5 1
输出
1504
*/