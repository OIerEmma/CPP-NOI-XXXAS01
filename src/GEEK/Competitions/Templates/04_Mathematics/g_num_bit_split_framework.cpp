//
// Created by Geek.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

// x % 10 取末位，x / 10 去末位，循环到 x == 0

// N11T1 数字反转（保留符号，去掉前导 0）
int reverseNum(int x) {
    int sign = (x < 0) ? -1 : 1;
    x = abs(x);
    int r = 0;
    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return sign * r;
}

// N13T1 计数问题：1 ~ n 中数字 d 出现了几次
int countDigit(int n, int d) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int x = i; x > 0; x /= 10)
            if (x % 10 == d) cnt++;
    return cnt;
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