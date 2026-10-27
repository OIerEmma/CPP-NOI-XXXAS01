//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum1(ll n) { return n * (n + 1) / 2; } // 1 + 2 + … + n
ll sum2(ll n) { return n * (n + 1) * (2 * n + 1) / 6; } // 1² + 2² + … + n²（n ≤ 1e6 不溢出）
ll arith(ll a1, ll an, ll cnt) { return (a1 + an) * cnt / 2; } // 等差数列求和

// 打表找规律：先写一个暴力 brute(n) 输出前若干项观察
ll brute(int n) {
    ll s = 0;
    for (int i = 1; i <= n; i++) s += i % 3; // 换成题目要求的暴力计算
    return s;
}

void printTable() {
    for (int n = 1; n <= 20; n++)
        cout << n << ": " << brute(n) << "\n"; // 看出规律后写公式，再用暴力对拍
}

int main() {
    return 0;
}