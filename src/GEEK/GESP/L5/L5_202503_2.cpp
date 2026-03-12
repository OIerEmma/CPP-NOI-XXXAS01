//
// Created by Geek.Kwok on 2026/3/10.
//
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long

ll a, p, t;

// 快速幂算法
// a^b % p
ll quick_pow(ll a, ll b, ll p) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 != 0) {
            // b--;
            // ans = ((ans % p) * (a % p)) % p;
            ans = (ans * (a % p)) % p;
        }
        b /= 2;
        // a = ((a % p) * (a % p)) % p;
        a = (a * a) % p;
    }
    return ans;
}

int main() {
    // cout << quick_pow(2, 10, 25) << endl;
    // return 0;
    cin >> t;
    while (t--) {
        cin >> a >> p;
        // 第二条：g^(p−1) % p = 1 (费马小定理)
        // if (quick_pow(a, p-1, p) != 1) {
        //     cout << "NO" << endl;
        //     continue;
        // }
        // 第三条：对于任意 1 ≤ i < p−1，均有 g^i % p ≠ 1
        bool f = true;
        for (int i = 2; i * i <= p - 1; i++) {
            if ((p - 1) % i == 0) {
                if (quick_pow(a, i, p) == 1 || quick_pow(a, (p - 1) / i, p) == 1) {
                    f = false;
                    break;
                }
            }
        }
        if (f) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}