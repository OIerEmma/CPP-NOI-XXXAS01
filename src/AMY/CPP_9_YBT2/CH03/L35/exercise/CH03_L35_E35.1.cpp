//
// Created by Amy on 2026/7/14.
//
#include <iostream>
using namespace std;

int main() {
    long long n, k;
    if (!(cin >> n >> k)) return 0;
    long long factor = k + 1;
    long long t = 0;
    long long cur = 1;
    while (cur < n) {
        t++;
        if (cur > n / factor) {
            break;
        }
        cur *= factor;
    }

    cout << t << endl;
    return 0;
}
