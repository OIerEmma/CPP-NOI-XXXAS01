//
// Created by Emme.Kwok on 2026/2/1.
//
#include<iostream>
using namespace std;

long long jiech(long long x) {
    if (x == 0) {
        return 1;
    }
    return x * jiech(x - 1);
}

long long c(long long n, long long i) {
    return jiech(n) / (jiech(i) * jiech(n - i));
}

int main() {
    long long m, n;
    cin >> m >> n;
    long long ans = n - 1;
    for (long long i = 2; i <= m - 2; i++) {
        ans += c(n - 2, i);
    }
    cout << ans % 100003 * (n - 1) % 100003 << endl;
    return 0;
}