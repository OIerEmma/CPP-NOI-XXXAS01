//
// Created by Amy on 2026/3/7.
//
#include<iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    if (y % x == 0) {
        cout << n - y / x;
    } else {
        cout << n - (y / x + 1);
    }
    return 0;
}
