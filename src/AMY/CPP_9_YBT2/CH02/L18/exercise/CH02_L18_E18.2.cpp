//
// Created by Amy on 2026/6/14.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    if (y % x == 0) {
        cout << n - y / x;
    }
    else if (n <= y / x) {
        cout << "0";
    }
    else {
        cout << n - y / x - 1;
    }
    return 0;
}