//
// Created by Amy on 2026/6/14.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n >= 30) {
        cout << n * (50 - 2);
    }else {
        cout << 50 * n;
    }
    return 0;
}