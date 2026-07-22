//
// Created by Amy on 2026/7/7.
//
#include<bits/stdc++.h>
using namespace std;

int bcs, cs, n, s;

int main() {
    cin >> bcs >> cs >> n;
    for (int i = 1; i <= n; i++) {
        s = bcs * 10 / cs;
        bcs = bcs * 10 % cs;
    }
    cout << s;
    return 0;
}