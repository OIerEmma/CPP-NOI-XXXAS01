//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 准确的整数平方根：返回最大的r，使 r*r <= x (x >= 0, x <= 1e18)
ll isqrt(ll x) {
    ll r = (ll) sqrt((double) x);
    while (r * r > x) r--; // sqrt 偏大时往下修
    while ((r + 1) * (r + 1) <= x) r++; // sqrt 偏小时往上修
}

bool isSquare(ll x) {
    if (x < 0) return false;
    ll r = isqrt(x);
    return r * r == x;
}

int main() {

    return 0;
}