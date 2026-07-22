//
// Created by Amy on 2026/7/7.
//
#include<bits/stdc++.h>
using namespace std;

long long n, fac = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) fac *= i;
    cout << fac;
    return 0;
}