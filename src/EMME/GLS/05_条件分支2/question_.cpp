//
// Created by Emme.Kwok on 2026/1/9.
//
#include<iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long cnt = (n + 1) / 2;
    if (k <= cnt) {
        cout << k * 2 - 1;
    } else {
        cout << (k - cnt) * 2;
    }
    return 0;
}