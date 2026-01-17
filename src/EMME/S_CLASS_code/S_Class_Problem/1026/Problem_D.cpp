//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int n2 = n;
    n -= a;
    n -= b;
    n -= c;
    if (n >= 0) {
        cout << n << " " << "YES" << endl;
    } else {
        cout << n << " " << "NO" << endl;
    }
    return 0;
}