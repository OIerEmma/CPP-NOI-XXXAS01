//
// Created by Geek.Kwok on 2026/10/23.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

// 最大公约数、最小公倍数
ll gcd(ll a, ll b) {
    return  b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// 分数：约分、保证分母为正
struct Frac {
    ll p, q;
};

Frac makeFrac(ll p, ll q) { // q ≠ 0
    if (q < 0) p = -p, q = -q;
    ll g = gcd(llabs(p), q);
    return {p / g, q / g};
}

// J23T3 的输出规则：分母为 1 时只输出分子
void printFrac(Frac f) {
    if (f.q == 1) cout << f.p;
    else cout << f.p << "/" << f.q;
}

// 比较 a/b 与 c/d 的大小（b > 0，d > 0）：交叉相乘，避免浮点误差
bool fracLess(ll a, ll b, ll c, ll d) {
    return a * d < b * c;
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