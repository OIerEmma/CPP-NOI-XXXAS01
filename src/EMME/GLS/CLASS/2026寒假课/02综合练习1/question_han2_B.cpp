//
// Created by Emme.Kwok on 2026/2/1.
//
#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << max(a1, max(a2, a3)) - min(a1, min(a2, a3)) << endl;
    return 0;
}