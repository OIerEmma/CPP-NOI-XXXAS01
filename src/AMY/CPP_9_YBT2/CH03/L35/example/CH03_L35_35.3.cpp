//
// Created by Amy on 2026/7/14.
//
#include<bits/stdc++.h>
using namespace std;
long long n, m, r;
int main() {
    cin >> m >> n;
    r = m % n;
    while (r != 0) {
        m = n;
        n = r;
        r = m % n;
    }
    cout << n << endl;
    return 0;
}