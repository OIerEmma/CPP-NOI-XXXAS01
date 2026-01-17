//
// Created by Emma on 2025/2/6.
//
#include<iostream>
using namespace std;

int main() {
    int n = 1, k;
    double s = 0.0;
    cin >> k;
    while (s <= k) {
        s += 1.0 / n;
        n++;
    }
    cout << n - 1 << endl;
    return 0;
}