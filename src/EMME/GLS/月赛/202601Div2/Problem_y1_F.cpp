//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

map<long long, int> m;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n;
    cin >> n;
    long long k, l, d;
    for (int i = 1; i <= n; i++) {
        cin >> k >> l >> d;
        for (int j = 1; j <= k; j++) {
            m[l + (j - 1) * pow(2, d)]++;
        }
    }
    for (auto p:m) {
        if (p.second % 2 == 1) {
            cout << p.first << endl;
            exit(0);
        }
    }
    return 0;
}