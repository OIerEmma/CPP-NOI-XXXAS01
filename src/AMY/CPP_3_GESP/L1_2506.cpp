//
// Created by Amy on 2026/3/7.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    int sum = min(n, k * t);
    cout << sum << endl;
    return 0;
}