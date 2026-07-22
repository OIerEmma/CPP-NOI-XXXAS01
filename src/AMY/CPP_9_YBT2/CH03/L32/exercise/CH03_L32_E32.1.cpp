//
// Created by Amy on 2026/7/11.
//
#include <iostream>
using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;
    for (int m = 1; ; ++m) {
        sum += 1LL * m * m * m;
        if (sum > n) {
            cout << m - 1 << endl;
            return 0;
        }
    }
}