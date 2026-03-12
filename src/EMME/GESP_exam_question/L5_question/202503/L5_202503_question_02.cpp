//
// Created by Emme.Kwok on 2026/3/10.
//
#include<iostream>
using namespace std;

#define ll long long

ll a, p, t;

ll qpow (ll a, ll b, ll p) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * (a % p) % p;
        }
        b /= 2;
        a = a * a % p;
    }
    return ans;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> p;
        bool flag = false;
        for (int i = 2; i * i <= p - 1; i++) {
            if ((p - 1) % i == 0) {
                if (qpow(a, i, p) == 1 || qpow(a, (p - 1) / i, p) == 1) {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}