//
// Created by Emme.Kwok on 2026/9/25.
//
#include<bits/stdc++.h>
using namespace std;

long long ksm(long long a, int b, int p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << ksm(a, b, p) << endl;
    return 0;
}