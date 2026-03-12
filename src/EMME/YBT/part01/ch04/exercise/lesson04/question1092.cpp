//
// Created by Emma on 2025/1/5.
//
#include<iostream>
using namespace std;

int main() {
    long long n, t = 1;
    long double e = 1.0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        t *= i;
        e += static_cast<long double>(1.0) / t;
    }
    // cout << e << endl;
    printf("%.10Lf\n", e);
    return 0;
}