//
// Created by Geek.Kwok on 2026/3/17.
//
#include <bits/stdc++.h>
using namespace std;

int n, group;
int a[n + 1];
map<int, int> mp;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    mp[a[1]] = ++group;
    for (int i = 2; i <= n; i++) {
        int initGroup = 1;
        bool f = true;
        for (auto p: mp) {
            if (gcd(p.first, a[i]) != 1) {
                curGroup
                break;
            }
        }
        mp[a[i]] = ++group;
    }
    return 0;
}