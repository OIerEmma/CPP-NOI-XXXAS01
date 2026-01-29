//
// Created by Emme.Kwok on 2026/1/27.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int n;
    cin >> n;
    int mi = 1;
    cout << n << "=";
    while (mi < n) {
        cout << mi << "+";
        n -= mi;
        mi *= 2;
    }
    cout << n << endl;
    return 0;
}